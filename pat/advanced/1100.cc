#include <cstdio>
#include <cstring>
#include <string>

char f[][5] = {
  "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
char s[][5] = {
  "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};
const int N = 10;
char input[N];

int main() {
  int n;
  scanf("%d", &n); getchar();
  for (int i = 0; i < n; ++i) {
    fgets(input, N, stdin);
    input[strlen(input) - 1] = '\0';
    
    if (input[0] >= '0' && input[0] <= '9') {
      int x = std::stoi(input);
      int sec = x / 13;
      int fir = x % 13;
      if (sec > 0 && fir) {
        printf("%s %s\n", s[sec], f[fir]);
      } else if (!fir) {
        printf("%s\n", s[sec]);
      } else {
        printf("%s\n", f[x]);
      }
    } else {
      char *pch = strtok(input, " ");
      int x = 0;
      bool sec = false;
      while (pch != NULL) {
        for (int k = 0; k < 13; ++k) {
          if (strcmp(pch, f[k]) == 0) {
            x = x * 13 + k; 
            sec = false; break;
          }
          if (strcmp(pch, s[k]) == 0) {
            x = x * 13 + k; 
            sec = true; break;
          }
        }
        pch = strtok(NULL, " ");
      }
      if (sec) {
        x *= 13;
      }
      printf("%d\n", x);
    }
  }
  return 0;
}
