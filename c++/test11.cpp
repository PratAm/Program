ing namespace std;
struct node {
	    int data;
			    struct node *left, *right;
}

void printLeftmostElement( struct node* root) 
{
	  
	   if(!root)
			      return NULL;
		      
		    std::queue<struct node *> first;
				   std::queue<struct node *> second;
					    
					   
					    first.push(root);
							   
							   while( !first.empty() || !second.empty())
									    {
												     while(!first.empty())
															      {
																			         func(first, second);
																							      }
														     
														      while( !second.empty())
																		     {
																					         func(second, first);
																									      }
																	    }
}


void func(first, second){
	        cout << second.front()->data << " " ;
					        if(second.front()->left)
										          first.push(second.front()->left);
									        if(second.front()->right) 
														          first.push(second.front()->right);         
													         second.pop();
}

