#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n,k,x,y,qnt;
string dir;
string vdir[4] = {"Esquerda", "Direita", "Cima", "Baixo"};
struct tumba
{
	int x,y,qnt;
	string dir;

	tumba()
	{}
	
	tumba(int xx,int yy, string dirr, int qntt)
	{
		x = xx;
		y = yy;
		dir = dirr;
		qnt = qntt;
	}
};

vector<tumba> v;
vector< pair<int,int> > vinter;

pair<int,int> interT(tumba a, tumba b)
{
	if ((b.dir == vdir[0] || b.dir == vdir[1]) && (a.dir == vdir[1] || a.dir == vdir[0]) && a.x == b.x)
	{
		return make_pair(a.x, a.y);
	}
	else if ((b.dir == vdir[2] || b.dir == vdir[3]) && (a.dir == vdir[2] || a.dir == vdir[3]) && a.y == b.y)
	{
		return make_pair(a.x, a.y);
	}
	else if (b.dir == vdir[0] && a.dir == vdir[2] && a.x >= b.x && a.y <= b.y)
	{
		return make_pair(b.x, a.y);
	}
	else if (b.dir == vdir[0] && a.dir == vdir[3] && a.x <= b.x && a.y <= b.y)
	{
		return make_pair(b.x, a.y);
	}
	else if (b.dir == vdir[1] && a.dir == vdir[2] && a.x >= b.x && a.y >= b.y)
	{
		return make_pair(b.x, a.y);
	}
	else if (b.dir == vdir[1] && a.dir == vdir[3] && a.x <= b.x && a.y >= b.y)
	{
		return make_pair(b.x, a.y);
	}

	return make_pair(0,0);
}

bool interP(tumba a, pair<int,int> point)
{
	if (a.dir == vdir[0])
	{
		return point.first == a.x && point.second <= a.y;
	}
	else if (a.dir == vdir[1])
	{
		return point.first == a.x && point.second >= a.y;
	}
	else if (a.dir == vdir[2])
	{
		return point.second == a.y && point.first <= a.x;
	}
	else if (a.dir == vdir[3])
	{
		return point.second == a.y && point.first >= a.x;
	}
	return false;
}

int getBit(int mask, int curr)
{
	return (mask >> curr) & 1;
}

int setBit(int mask, int curr)
{
	return mask | (1 << curr);
}

ll solve(int curr, int mask, int qnt)
{
	if (curr == vinter.size() || qnt == k)
	{
		return 0;
	}

	ll sum = 0;
	int newmask = mask;
	for (int i = 0; i < n; ++i)
	{
		if (getBit(mask, i))
			continue;

		if (interP(v[i], vinter[curr]))
		{
			sum += (ll)v[i].qnt;
			newmask = setBit(newmask, i);
		}
	}
	ll ret = 0;
	ret = max(ret, solve(curr + 1, newmask, qnt + 1) + sum);
	ret = max(ret, solve(curr + 1, mask, qnt));

	return ret;
}

int main(void)
{
	while (cin >> n >> k)
	{
		v.clear();
		vinter.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y >> dir >> qnt;
			tumba tmp(x,y,dir,qnt);
			v.push_back(tmp);
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				pair<int,int> ret = interT(v[i], v[j]);
				if (ret != make_pair(0,0))
				{
					vinter.push_back(ret);
				}
				else
				{
					pair<int,int> ret = interT(v[j], v[i]);
					if (ret != make_pair(0,0))
					{
						vinter.push_back(ret);
					}
				}
			}
			vinter.push_back(make_pair(v[i].x,v[i].y));

		}

		cout << solve(0, 0, 0) << "\n";
	}
	return 0;
}