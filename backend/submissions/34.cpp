#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>
#define F first
#define S second
#define tc ll t;cin>>t;while(t--)
#define printv(v) for(auto x : v) cout<<x<<" ";cout<<endl;
#define printv2(v) for(auto i=0;i<v.size();i++){for(auto j=0;j<v[i].size();j++){cout<<v[i][j]<<" ";}cout<<endl;}
#define printm(m) for(auto x:m) cout<<x.first<<" "<<x.second<<endl;
const ll mod=1e9+7;
using namespace std;
const ll INF=1e9;


set<pair<ll, ll> > av;
struct Point {
    ll x, y;
};

ll ccw(Point a, Point b, Point c) {
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}

ll dist(Point p, Point q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

Point bottomLeft(vector<Point> points){
    Point bt=points[0];
    for(Point p:points)
        if(p.y<bt.y || p.y==bt.y && p.x<bt.x)
            bt=p;
    return bt;
}

struct cmp
{
    cmp(Point r_) : r(r_){}

    bool operator ()(const Point & p, const Point & q) const
    {
        long long compPolar = ccw(p, r, q);
        long long compDist = dist(p, r) - dist(q, r);
	    long long sexy=(compPolar == 0 ? compDist : compPolar);
		if (sexy <= 0)
			return true;
		return false;
    }

    Point r;
};

void sortByPolar(vector<Point> &points,Point r){
    sort(points.begin(), points.end(), cmp(r));

    Point p=points[0], q=points[points.size()-1];

    ll i=points.size()-2;
    while(i>=0 && ccw(p,q,points[i])==0)
        i--;

    for(ll l=i+1,h=points.size()-1;l<h;l++,h--){
        Point tmp = points[l];
        points[l] = points[h];
        points[h] = tmp;
    }
}


vector<Point> outerTrees(vector<Point> points){
    vector<Point> v;
    sortByPolar(points,bottomLeft(points));

    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    for(ll i=2;i<points.size();i++){
        Point top=st.top();
        st.pop();

        while(ccw(st.top(),top,points[i])<0){
            top=st.top();
            st.pop();
        }

        st.push(top);
        st.push(points[i]);
    }

    while(!st.empty()){
		Point tm = st.top();
		av.erase(make_pair(tm.x, tm.y));
        v.pb(tm);
        st.pop();
    }
    return v;
}




int tellme(long long Ax,long long Ay,long long Bx,long long By,long long X,long long Y)
	{
		long p = ((Bx - Ax) * (Y - Ay) - (By - Ay) * (X - Ax));
		if(p>0)return 1;
		if(p<0)return -1;
		return 0;
	}

bool check(vector<Point> &ar, ll X, ll Y)
{
	int n = ar.size();
	int sn = tellme(ar[n-1].x, ar[n-1].y, ar[0].x, ar[0].y, X, Y);

	if (sn == 0) return false;

	for (int i = 0; i < ar.size() - 1; i++)
		{
			if(tellme(ar[i].x,ar[i].y,ar[i+1].x,ar[i+1].y,X,Y) != sn)
				return false;
		}
		return true;
}


int main() {
    //fast;
    tc{
        ll n,q; cin>>n>>q;
        vector<Point> points;

		vector<vector<Point> > poly;

		av.clear();

		//cout << "debugging \n";

        for(ll i=0;i<n;i++){
            //cout << "here  " << i << "\n";
            ll x,y; cin>>x>>y;
			av.insert(make_pair(x, y));
            points.pb({x,y});
            //cout << "here  " << i << "\n";
        }
        //vector<vector<Point>> polygons=findPolygons(points);
        //cout << "here -1\n";
		while(av.size() >= 3)
		{
			vector<Point> poin;
			//cout << "here0\n";
			for (auto i : av)
				poin.pb({i.first, i.second});
            //cout << "here1\n";
			vector<Point> temp = outerTrees(poin);

			/**cout << "convex hull:\n";
			for (auto de : temp)
                cout << de.x << " " << de.y << endl;**/

			if (temp.size() <= 2)
				break;
			poly.pb(temp);

			//cout << "INF\n";
		}

        for(ll i=0;i<q;i++){
            ll a,b,count=0; cin>>a>>b;
            for(auto x:poly)
			{
			    /**cout << "\nconvex hull\n";
                for (auto de : x)
                    cout << de.x << " " << de.y << endl;**/


                if (x.size() <= 2)
					break;
				if (check(x, a, b))
					count++;
				else
					break;
				//count+=isInside(x,{a,b});
			}
            cout << count << "\n";
        }
    }

    return 0;
}
