
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int> adj[N];

     //creating a graph

     for(int i = 0 ;i < N ; i++)

     {

         if(Edge[i] != -1)

         adj[Edge[i]].push_back(i);

     }

     int val = 0;

     int ans = 0;

     // checking sum of incoming all nodes on a given node

     for(int i = 0 ; i < N ; i++)

     {

        int  sm  =0;

         for(auto x : adj[i])

         {

            sm = sm+x; 

         }

         if(sm >= val)

         {

             val = sm;

             ans = i;

         }

     }

     return ans;

     

  }
};