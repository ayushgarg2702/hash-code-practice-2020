#include<bits/stdc++.h>
using namespace std;

int main(void)
{
 long long int MaxNoOFSlice;
 long long int MaxNoOFPizza;
 long long int TotalPizza=0;

 cin>>MaxNoOFSlice>>MaxNoOFPizza;
 long long int Slice[MaxNoOFPizza];
 long long int i,j=-1;

 for(i=0;i<MaxNoOFPizza;i++)
 {
   cin>>Slice[i];

   if(Slice[i]>MaxNoOFSlice)
     j=i-1;
 }

 if(j==-1)
   j=i-1;

 long long int Fsize=0;
 long long int FinalIndex[j];
 long long int j1,v;

 for(j1=j;j1>=0;j1--)
 {
   long long int sum=0;
   long long int z[j+1]={0};
   long long int dif =0;
   long long int k;
   for(i=j1,v=0;i>=0;i--,v++)
   {
     if((sum+Slice[i])<=MaxNoOFSlice)
        {
          sum+=Slice[i];
          z[i]=1;
        }
      else
      {
          for(k=0;k<i;k++)
           {
             if(z[k]==1&&Slice[k]==(MaxNoOFSlice-sum+Slice[i]))
             {
               z[k]=0;
               z[i]=1;
               sum-=Slice[k];
               sum+=Slice[i];
             }
           }
      }

      if(v==j)
        break;
      if(i==0)
       i=j+1;
   }

    if(sum>Fsize)
    {
      Fsize=sum;
      for(i=0;i<=j;i++)
      {
        FinalIndex[i]=z[i];
      }
    }
  }

 for(i=0;i<=j;i++)
 {
   if(FinalIndex[i]==1)
    TotalPizza++;
 }

 cout<<TotalPizza<<endl;
 for(i=0;i<=j;i++)
 {
   if(FinalIndex[i]==1)
    cout<<i<<" ";
 }

 return 0;
}
