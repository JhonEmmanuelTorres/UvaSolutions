    #include <bits/stdc++.h>

    using namespace std;

    typedef pair<int,int> Edge;

    int main()
    {
        ios_base::sync_with_stdio( false );
        int n, m, t, answer, u, v, i, j;
        vector<Edge> graph;
        cin >> t;
        while( t-- )
        {
            cin >> n >> m;
            for( i = 0; i < m; i++ )
            {
                cin >> u >> v;
                if( u > v )
                    swap( u, v );
                graph.push_back( make_pair( u, v ) );
            }
            sort( graph.begin(), graph.end() );

            answer = 0;
            for( i = 0; i < m; i++ )
            {
                j = (lower_bound( graph.begin(), graph.end(), make_pair( graph[i].second, 1 ) ) - graph.begin());
                while( j < m && graph[j].first == graph[i].second )
                {
                    if( binary_search( graph.begin(), graph.end(), make_pair( graph[i].first, graph[j].second ) ) )
                        answer++;
                    j++;
                }
            }
            cout << answer << endl;
            graph.clear();
        }
        return 0;
    }
