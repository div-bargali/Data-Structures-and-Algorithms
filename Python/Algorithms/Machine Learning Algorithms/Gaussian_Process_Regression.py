# Gaussian Process Regression

import numpy as np
import scipy.optimize


class GaussianProcessRegression:
    """
    Gaussian Process Regression with square exponential kernel
    """

    def __init__(self, X, Y, noise=1., sigma=1., ell=1.):
        """
        Initializes gaussian process regression.

        :param X: Data, (N, 1) numpy array
        :param Y: Function values, (N, 1) numpy array
        :param noise: Measurement noise, float
        :param sigma: Gain, float
        :param ell: Length scale, float
        """
        self.X = X
        self.Y = Y
        self.noise = noise
        self.kernel = SquareExponential(sigma, ell)
        self.L, self.alpha = self.invert_gram_matrix()

    def invert_gram_matrix(self):
        """
        Calculates and inverts the gram matrix with cholesky decomposition.

        :return: Lower triangular cholesky factor of the gram matrix, (N, N) numpy array
                 Inverted gram matrix multiplied with the function values Y, (N, N) numpy array
        """
        kXX = self.kernel.k(self.X, self.X)
        gram_matrix = kXX + self.noise ** 2 * np.eye(X.shape[0])
        L = np.linalg.cholesky(gram_matrix)
        alpha = np.linalg.solve(L.T, np.linalg.solve(L, self.Y))
        return L, alpha

    def neg_log_marginal_likelihood(self):
        """
        Calculates the negative logarithm of the marginal likelihood. The marginal likelihood is a multivariate
        gaussian with 0 mean and the gram_matrix as covariance-matrix.

        :return: Negative log marginal likelihood, float
        """
        return 0.5 * (self.Y.T @ self.alpha)[0, 0] + np.sum(np.log(np.diag(self.L)))

    def dml_dtheta(self, theta):
        """
        Calculate the derivative of the negative log marginal likelihood w.r.t the parameters of the kernel.

        :param theta: Parameters of the kernel, (2, 1) numpy array
        :return: Negative log marginal likelihood, float
                 Derivative, (2, 1) numpy array
        """
        self.kernel = SquareExponential(theta[0], theta[1])
        self.L, self.alpha = self.invert_gram_matrix()

        dml_dtheta = []
        for dk_dtheta in [self.kernel.dk_dsigma(self.X), self.kernel.dk_dell(self.X)]:
            dml_dtheta.append(
                -0.5 * (self.alpha.T @ dk_dtheta @ self.alpha)[0, 0]
                + 0.5 * np.trace(np.linalg.solve(self.L.T, np.linalg.solve(self.L, dk_dtheta)))
            )
        return self.neg_log_marginal_likelihood(), np.array(dml_dtheta)

    def train(self):
        """
        Trains the gaussian process regression by optimizing the negative log marginal likelihood w.r.t the
        parameters of the kernel.

        """
        theta = np.array([self.kernel.sigma, self.kernel.ell])
        res = scipy.optimize.minimize(self.dml_dtheta, theta, jac=True, options={'maxiter': 25})
        print('Optimized values: sigma = %.3f, ell = %.3f' % (res.x[0], res.x[1]))

    def predict(self, x):
        """
        Predicts function values of unseen data x using gaussian process regression.

        :param x: Unseen data, (N, 1) numpy array
        :return: Point estimates of the function values, (N, 1) numpy array
                 Covariance matrix of the function values, (N, N) numpy array
        """
        kxx = self.kernel.k(x, x)
        kXx = self.kernel.k(self.X, x)
        gain = np.linalg.solve(self.L.T, np.linalg.solve(self.L, kXx)).T
        mu_post = gain @ self.Y
        cov_post = kxx - gain @ kXx
        return mu_post, cov_post


class SquareExponential:
    """
    Square Exponential kernel
    """

    def __init__(self, sigma=1., ell=1.):
        """
        Initializes the square exponential kernel.

        :param sigma: Gain, float
        :param ell: Length scale, float
        """
        self.sigma = sigma
        self.ell = ell

    def k(self, A, B):
        """
        Calculate the kernel matrix.

        :param A: Input matrix, (N, 1) numpy array
        :param B: Input matrix, (N, 1) numpy array
        :return: Kernel matrix, (N, N) numpy array
        """
        return self.sigma ** 2 * np.exp(-squared_l2_norm(A, B) / (2. * self.ell ** 2))

    def dk_dsigma(self, X):
        """
        Derivative of the kernel matrix with respect to sigma.

        :param X: Data, (N, 1) numpy array
        :return: Derivative w.r.t sigma (N, N) numpy array
        """
        return 2 * self.k(X, X) / self.sigma

    def dk_dell(self, X):
        """
        Derivative of the kernel matrix with respect to ell.

        :param X: Data, (N, 1) numpy array
        :return: Derivative w.r.t ell (N, N) numpy array
        """
        return self.k(X, X) * squared_l2_norm(X, X) / self.ell ** 3


def squared_l2_norm(A, B):
    """
    Helper function to calculate the squared l2 norm between each possible combination of the rows of A and B.

    :param A: Input matrix, (N, 1) numpy array
    :param B: Input matrix, (N, 1) numpy array
    :return: Matrix of l2 norm, (N, N) numpy array
    """
    return np.array([[np.sum((A[i, :] - B[j, :]) ** 2)
                      for j in range(B.shape[0])]
                     for i in range(A.shape[0])])


def f(x):
    """
    Example function to test GP regression.

    :param x: Data, (N, 1) numpy array
    :return: Function values, (N, 1) numpy array
    """
    return (6 * x - 2) ** 2 * np.sin(12 * x - 4)


# Execute GP regression with a sample dataset
if __name__ == "__main__":
    import matplotlib.pyplot as plt

    # Create a sample dataset with random noise
    noise = 0.4
    X = np.linspace(0, 1.0, 10).reshape(-1, 1)
    Y = f(X) + noise * np.random.randn(*X.shape)

    # Fit GP regression to the data
    GP = GaussianProcessRegression(X, Y, noise=noise)
    GP.train()

    # Predict unseen data
    x = np.linspace(-0.2, 1.2, 100).reshape(-1, 1)
    y_pred, cov_pred = GP.predict(x)

    # Plot the data
    plt.figure(1, figsize=(8, 4))
    plt.fill_between(
        x.ravel(),
        y_pred.ravel() - 1.96 * np.sqrt(np.diag(cov_pred)),
        y_pred.ravel() + 1.96 * np.sqrt(np.diag(cov_pred)),
        color='C1',
        alpha=0.3,
        label='95%'
    )
    plt.plot(x, y_pred, 'C1', label='Prediction')
    plt.plot(x, f(x), 'k', label='Real function')
    plt.scatter(X, Y, alpha=1, marker='o', color='C0', label='Data')
    plt.legend()
    plt.show()
