#include<bits/stdc++.h>
using namespace std;
#define d 256    // for all valid characters in ASCII
void search(char pattern[], char text[], int q) { 
    int M = strlen(pattern), N = strlen(text); 
    int i, j; 
    int pattern_hash = 0;    // value of hash for pattern 
    int text_hash = 0;       // value of hash for text 
    int h = 1; 
    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    } 
    // Calculate the hash value of pattern and first 
    // window of text 
    for (i = 0; i < M; i++) { 
        pattern_hash = (d * pattern_hash + pattern[i]) % q; 
        text_hash = (d * text_hash + text[i]) % q; 
    } 
    // Slide the pattern over text one by one 
    for (i = 0; i <= N - M; i++) { 
        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one 
        if ( pattern_hash == text_hash ) { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) { 
                if (text[i+j] != pattern[j]) 
                    break; 
            } 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                cout<<"Pattern found at index "<< i<<endl; 
        } 
        // Calculate hash value for next window of text: Remove 
        // leading digit, add trailing digit 
        if ( i < N-M ) { 
            text_hash = (d*(text_hash - text[i]*h) + text[i+M])%q; 
            // We might get negative value of t, converting it 
            // to positive 
            if (text_hash < 0) 
            text_hash = (text_hash + q); 
        } 
    } 
} 
int main() { 
    char text[] = "GOODBYE BYE TATA BADBYE"; 
    char pattern[] = "BYE";
    int q = 101; 
    search(pattern, text, q); 
    return 0; 
} 