#include <iostream>

using namespace std;

int main()
    {
        int n;
        cout<<"No Of Vertices"<<endl;
        cin>>n;
        int A[n][n],P[n][n],C[n][n];
        cout<<"Adjacency Matrix"<<endl;
        for(int i=0;i<n;i++)
            {
               for(int j=0;j<n;j++)
                    {
                        cin>>A[i][j];
                        P[i][j]=A[i][j];
                    }
            }
        
        for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                            {
                                P[i][j]=(P[i][j]|(P[i][k]&P[k][j]));
																	 
                            }
                    }
            }
        
	cout<<"Path Matrix"<<endl;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        cout<<P[i][j]<<" ";
                    }
                cout<<endl;
            }
	
	
        return 0;

    }
