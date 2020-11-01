// Binary search | Swift
func binarySearch(in numbers: [Int], for value: Int) -> Int?
{
    var left = 0
    var right = numbers.count - 1

    while left <= right {

        let middle = Int(floor(Double(left + right) / 2.0))

        if numbers[middle] < value {
            left = middle + 1
        } else if numbers[middle] > value {
            right = middle - 1
        } else {
            return middle
        }
    }

    return nil
}
// Driver code
let numbers = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
let value = 17

if let index = binarySearch(in: numbers, for: value) {
    print("Found \(value) at index \(index)")
} else {
    print("Did not find \(value)")
}
