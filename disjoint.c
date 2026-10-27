#include<stdio.h>
#define MAX 20
int parent[MAX];
int rank[MAX];

void makeset(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unionset(intx,inty){
    int rootX=find(x);
    int rootY=find(y);
    if ( rootX==rootY){
        printf("%d and %d are in same set\n ",x,y);
    }
    if(rank[rootX]<rank[rootY]){
        parent[rootX]=rootY;
    }
    else if(rank[rootX]>rank[rootY]){
        parent[rootY]=rootX;
    }
    else{
        parent[rootY]=rootX;
        rank[rootX]++;
    }
    
}
int display(int n){
    printf("\tElement\tparent\trank");
    for(int i=0;i<n;i++){
        printf("%d\t %d\t %d\t ",i,parent[i],rank[i]);

    }
}
int main(){
    int n,choice,x,y;
    printf("Enter no of elements:\n");
    scanf("%d",&n);

    makeset(n);
    printf("1.find");
    printf("2.union");
    printf("3.display");
    printf("4.exit");
    while (1){
        printf("enter choice");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("\nenter elements:\n");
            scanf("%d"&x);
            printf("rep of %d is %d");
            scanf("%d %d",&x,find(x));
            break;
           case 2:
           printf("enter 2 elements:");
           scanf("%d%d",&x,&y);
           unionSet(x, y);
            break;
case 3:
 display(n);
break;

 case 4:
default:
 printf(&quot;Invalid choice!\n&quot;);
            
        }
    }
}