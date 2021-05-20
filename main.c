#include <stdio.h>

int main() {
    int k,min;

    int pages[25];

    int memory[10];

    int count[10];

    int flag[25];

    int n; //length of ref str

    int f; //number of frames

    int pf = 0; //page fault counter

    int next = 1;


    printf("Enter the length of reference string:\n");
    scanf("%d", &n);


    printf("Enter the reference string:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
        flag[i] = 0;
    }


    printf("Enter the number of frames:\n");
    scanf("%d", &f);


    //initialization
    for(int i=0;i<f;i++){
        count[i] = 0; //not referenced
        memory[i] = -1; //empty
    }


    printf("\nLRU - page replacement:\n\n");

    for(int i=0;i<n;i++){ //iterate over n eles in pages[]

        for(int j=0;j<f;j++){

            if(memory[j] == pages[i]){ //found in frames
                flag[i] = 1;
                count[j] = next; //next:1 count of page ref now in mem
                next++; //next:2
            }

        }

        if(flag[i]==0){ //not found in frames
            if(i<f){ //mem still have free slots
                memory[i] = pages[i];
                count[i] = next;
                next++;
            }else{
                min = 0; //the first element in the count array as cmp tar

                for(int j=1; j<f; j++)
                    if(count[min]>count[j])min = j;
                    memory[min] = pages[i]; //min indexing(LRU)->replacement
                    count[min] = next;
                    next++;



            }
            pf++; //counter of page fault++
        }


        //mem display
        for(int j=0; j<f; j++){
            printf("%d\t", memory[j]);
        }


        if(flag[i]==0){
            printf("Page fault");
            printf("\n");
        }


    }


    printf("\nThe number of page faults using LRU is %d\n",pf);

    return 0;
}
