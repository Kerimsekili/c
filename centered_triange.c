int main() {
    int n;
    
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for (int star = 0; star < 2 * i + 1; star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
