#include<stdio.h>
 
int findLRU(int count[], int n){
    int i, min=count[0], pos=0;
 
    for(i = 1; i < n; ++i){
        if(count[i] < min){
            min=count[i];
            pos=i;
        }
    }
    
    return pos;
}
 
int main()
{
    int nof, nop, m[10], rs[30], next=0, count[10], flag1, flag2, i, j, pos, pf=0;
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    
    printf("Enter number of pages: ");
    scanf("%d", &nop);
    
    printf("Enter reference strings: \n");
    
    for(i = 0; i < nop; ++i)
    {
	printf("String %d:",i+1);
        scanf("%d", &rs[i]);
    }
    
    for(i = 0; i < nof; ++i){
        m[i] = -1;
    }
    
    for(i = 0; i < nop; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < nof; ++j){
            if(m[j] == rs[i]){
                next++;
                count[j] = next;
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if(flag1 == 0){
            for(j = 0; j < nof; ++j){
                if(m[j] == -1){
                    next++;
                    pf++;
                    m[j] = rs[i];
                    count[j] = next;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            pos = findLRU(count, nof);
            next++;
            pf++;
            m[pos] = rs[i];
            count[pos] = next;
        }
        
        printf("\n");
        
        for(j = 0; j < nof; ++j){
            printf("%d\t", m[j]);
        }
    }
    
    printf("\n\nTotal Page fault= %d\n", pf);
    
    return 0;
}
