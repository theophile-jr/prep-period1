char ** read_tab(int n) {
   int i,j;
   char ** tab;
   tab = (char **) malloc(sizeof(char*)*n);
   for (i=0;i<n;i++) {
      tab[i] = (char*) malloc(sizeof(char)*n);
      for (j=0;j<n;j++) {
         tab[i][j] = getchar();
      }
      getchar();
   }
   return tab;
}

int main(void) {
   int n;
   char ** tab;
   int npossibilites = 0;
   scanf("%d",&n);
   getchar();
   tab = read_tab(n);
   int dp[n][n];
   
   for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
        if (tab[y][x] == '0') continue;


    }
   }

   npossibilites = dp[n - 1][n - 1];

   printf("%d\r\n",npossibilites);
   return 0;
}
