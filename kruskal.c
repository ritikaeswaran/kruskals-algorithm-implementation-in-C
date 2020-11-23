#include<stdio.h> 

struct edge 

{ 

int a; 

int b; 

int w; 

}arr[100]; 

 

int par[100],rank[100]; 

int find(int a) 

{ 

if(par[a]==-1) 

{ 

return a; 

} 

else 

{ 

return par[a]=find(par[a]); 

} 

} 

void merge(int a,int b) 

{ 

if(rank[a]<rank[b]) 

{ 

par[a]=b; 

rank[b]+=rank[a]; 

} 

else 

{ 

par[b]=a; 

rank[a]+=rank[b]; 

} 

 

 

} 

 

int main() 

{ 

int n,m,a,b,w,i,j,temp; 

printf("enter the number of vertices......"); 

scanf("%d",&n); 

printf("enter the number of edges......"); 

scanf("%d",&m); 

for(i=0;i<n;i++) 

{ 

par[i]=-1; 

rank[i]=1; 

} 

printf("enter the source destination and weight...."); 

for(i=0;i<m;i++) 

{ 

scanf("%d",&arr[i].a); 

scanf("%d",&arr[i].b); 

scanf("%d",&arr[i].w); 

} 

int sum=0; 

for(i=0;i<m;i++) 

{ 

for(j=0;j<m-1-i;j++) 

{ 

if(arr[j].w>arr[j+1].w) 

{ 

temp=arr[j].w; 

    arr[j].w=arr[j+1].w; 

    arr[j+1].w=temp; 

     

    temp=arr[j].a; 

    arr[j].a=arr[j+1].a; 

    arr[j+1].a=temp; 

     

     

    temp=arr[j].b; 

    arr[j].b=arr[j+1].b; 

    arr[j+1].b=temp; 

} 

} 

} 

printf("\nthe edges required to construct minimum cost spanning tree are...."); 

for(i=0;i<m;i++) 

{ 

a=find(arr[i].a); 

b=find(arr[i].b); 

if(a!=b) 

{ 

sum+=arr[i].w; 

printf("\n\n%d-----%d   %d",arr[i].a,arr[i].b,arr[i].w); 

merge(a,b); 

} 

} 

printf("\n\nthe sum of the edge weight of the minimum cost spanning tree is...."); 

printf("%d",sum); 

} 
