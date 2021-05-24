 #include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class priorityqueue
{
  vector<int> pq;
  public:
  priorityqueue()
  {

  }
  bool isempty()
  {
    return pq.size()==0;
  }
  int getmin()
  {
    if(isempty())
    {
      return 0;
    }
    return pq[0];
  }
  int getsize()
  {
    return pq.size();
  }
  void insert(int element)
  {
    pq.push_back(element);
    int childindex=pq.size()-1;
    while(childindex>0)
    {
      int parentindex=(childindex-1)/2;
      if(pq[childindex]<pq[parentindex])
      {
        int temp = pq[parentindex];
        pq[parentindex]=pq[childindex];
        pq[childindex]=temp;
      }
      else
      {
        break;
      }
      childindex=parentindex;
      
    }
  }
  int removemin()
  {
    if(isempty())
    {
      return 0;
    }
    int ans = pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();
    int parentindex=0;
    int leftchildindex=2*parentindex+1;
    int rightchildindex=2*parentindex+2;
    while(leftchildindex<pq.size())
    {
      int minindex = parentindex;
      if(pq[leftchildindex]<pq[minindex])
      {
        minindex=leftchildindex;
      }
      if(pq[rightchildindex]<pq[minindex] && rightchildindex<pq.size())
      {
        minindex=rightchildindex;
      }
      if(minindex==parentindex)
      {
        break;
      }
      int temp =pq[minindex];
      pq[minindex]=pq[parentindex];
      pq[parentindex]=temp;
      parentindex=minindex;
      leftchildindex=2*parentindex+1;
      rightchildindex=2*parentindex+2;
    }
    return ans;
  }
};
void ksortedarray(int input[],int k,int n)
{
  priority_queue<int> pq;
  for(int i=0;i<k;i++)
  {
    pq.push(input[i]);
  }
  int j=0;
  for(int i=k;i<n;i++)
  {
    input[j]=pq.top();
    pq.pop();
    pq.push(input[i]);
    j++;
  }
  while(!pq.empty())
  {
    input[j]=pq.top();
    pq.pop(); 
  }
}
int main()
{
  int input[]={10,12,6,7,9};
  int k=3;
  ksortedarray(input, k, 5);
  for(int i=0;i<5;i++)
  {
    cout<<input[i]<<" ";
  }
}