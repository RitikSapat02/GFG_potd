class Solution

{

public:

    // function to construct tree from string

    Node *solve(string str,int s,int e)

    {

        if(s>e) return NULL;

        int i=s+1;

        int num=0;

        for(;i<=e&&!(str[i]=='('||str[i]==')');i++)

         { 

           int a=(str[i]-'0');

           num=num*10+a;

         } 

        Node *root=new Node(num);

        if(i>=e)

          return root;

        stack<int> st;

        st.push(i);

        int f=i;

        while(!st.empty())

        {

            i++;

            if(str[i]=='(')

              st.push(i);

            else if(str[i]==')'&&str[st.top()]=='(')

              st.pop();

        }

        root->left=solve(str,f,i);

        root->right=solve(str,i+1,e-1);

        return root;

    }

    Node *treeFromString(string str)

    {

        // code here

        if(str.size()==0) return NULL;

        string x="("+str+")";

        return solve(x,0,x.size()-1);

    }

};