#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include "PreOrderTree.h"
using namespace std;
class treeLevelOrder
{
public:
	treeLevelOrder();


		void levelOrderBottom(TreeNode* root) {
			queue<TreeNode*> s;
			TreeNode* pcur = NULL;
			vector<int> temp;
			if (root){
			s.push(root);
			}
			while (!s.empty()){
				int v = s.size();
				for (int i = 0; i < v; i++){
				pcur = s.front();
				printf("%d ", pcur->val);
				s.pop();
				if (pcur->left)
				s.push(pcur->left);
				if (pcur->right)
				s.push(pcur->right);
				}
				cout << endl;
			}			
		}


	~treeLevelOrder();
};

