#include <stdio.h>
 
#define MAX_TERMS 10
 

struct poly {
    int coeff; 
    int expo;  
};
 

int readPoly(struct poly p[]);
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void displayPoly(struct poly p[], int terms);
 
int main() {
    struct poly p1[MAX_TERMS], p2[MAX_TERMS], p3[MAX_TERMS];
    int t1, t2, t3;
 
    
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);
 
    
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);
 
    
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);
 
    return 0;
}
 
int readPoly(struct poly p[]) {
    int t, i;
 
    printf("\nEnter the total number of terms in the polynomial (max %d): ", MAX_TERMS);
    scanf("%d", &t);
 
    if (t > MAX_TERMS) {
        printf("Error: Maximum number of terms is %d.\n", MAX_TERMS);
        return 0;
    }
 
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
 
    return t;
}
 
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;
 
    
    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
        }
        k++;
    }
 
    
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
 
   
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
 
    return k; 
}
 
void displayPoly(struct poly p[], int terms) {
    int k;
 
    for (k = 0; k < terms - 1; k++) {
        printf("%d(x^%d) + ", p[k].coeff, p[k].expo);
    }
    printf("%d(x^%d)", p[terms - 1].coeff, p[terms - 1].expo);
}