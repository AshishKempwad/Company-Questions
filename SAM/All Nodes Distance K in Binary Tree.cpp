https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/629705/Using-BFS-oror-C%2B%2B



 vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        CountDistanceK(root,target,K,ans);
        return ans;
    }
    int CountDistanceK(TreeNode *root, TreeNode *target, int K,vector<int> &ans)
    {
        if(root==NULL)
            return -1;
        if(root==target)
        {
            PushNodes(target,K,ans);
            return 0;
        }
        int l=CountDistanceK(root->left, target,K, ans);
        if(l!=-1)
        {
            if((l+1)==K)
                ans.push_back(root->val);
            else
                PushNodes(root->right,K-2-l,ans);
            return l+1;
        }
        int r=CountDistanceK(root->right,target,K,ans);
        if(r!=-1)
        {
            if((r+1)==K)
                ans.push_back(root->val);
            else
                PushNodes(root->left,K-2-r,ans);
            return r+1;
        }
        return -1;
    }
    void PushNodes(TreeNode * temp, int K,vector<int> &ans)
    {
        if(temp==NULL || K<0)
            return ;
        if(K==0)
            ans.push_back(temp->val);
        PushNodes(temp->left,K-1,ans);
        PushNodes(temp->right,K-1,ans);
    }
