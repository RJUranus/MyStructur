//
// Created by Di Yang on 2022/5/1.
//

#ifndef _MYMAP_H
#define _MYMAP_H

#include<iostream>
#include<queue>
#include <Vector>

#define MAX 32767
#define MVNum 100
#define MAXNum 100

using namespace std;

//邻接表信息
typedef struct Data {
    int wight;
};
typedef struct AN {//边界点
    int adj;
    struct AN *next;
    int wight;
} AN;
typedef struct VN {//顶点信息
    int data;
    AN *first;
} VN, AD[MAXNum];
typedef struct {
    AD vertices;
    int V, A;//V顶点，A边
} ALGraph;
//邻接表信息

//普利姆算法
struct {
    int adj, wight;
} CG[MAX];

//克鲁斯卡尔
struct KR {
    int head, tail;
    int wight;
} Edge[MAX];

class Map {
public:
    //无向图邻接矩阵
    void CreateUDN(Map &map) {
        cin >> map.VexNum >> map.arcNum;
        //for (int i = 0; i < map.VexNum; i++)cin >> map.v[i];
        for (int i = 0; i < map.VexNum; i++) map.v[i]=i;//上面那个是真的
        for (int i = 0; i < map.VexNum; i++)
            for (int j = 0; j < map.VexNum; j++)
                map.arcs[i][j] = MAX;//如果要输出矩阵为了好看请将MAX改为0，使用普利姆算法时这里不能为零
        for (int k = 0; k < map.arcNum; k++) {
            int WG;
            //cin >> v1 >> v2;//无权值
            cin >> v1 >> v2 >> WG;//有权值
            int i = LocateVex(map, v1);
            int j = LocateVex(map, v2);
            //map.arcs[i][j] = 1;//无权值
            map.arcs[i][j] = WG;//有权值
            map.arcs[j][i] = map.arcs[i][j];
            Edge[k].head = v1-1;
            Edge[k].tail = v2-1;
            Edge[k].wight = WG;//克鲁斯卡尔数组赋初值
        }
        //Print(map, map.VexNum);
        prim(map, 0);//普利姆测试
        //Kruskal(map);//克鲁斯卡尔测试
    }

    //有向图邻接矩阵
    void CreateHDM(Map &map) {
        cin >> map.VexNum >> map.arcNum;
        for (int i = 0; i < map.VexNum; i++)cin >> map.v[i];
        for (int i = 0; i < map.VexNum; i++)
            for (int j = 0; j < map.VexNum; j++)
                map.arcs[i][j] = 0;
        for (int k = 0; k < map.arcNum; k++) {
            //cin>>v1>>v2>>v3;带权
            cin >> v1 >> v2;
            int i = LocateVex(map, v1);
            int j = LocateVex(map, v2);
            //map.arcs[i][j]=v3;
            map.arcs[i][j] = 1;
        }
        Print(map, map.VexNum);
    }

    //无向图邻接表
    void CreateUDG(ALGraph &G) {
        cin >> G.V >> G.A;
        for (int i = 0; i < G.V; i++) {
            cin >> G.vertices[i].data;
            G.vertices[i].first = NULL;
        }
        for (int k = 0; k < G.A; k++) {
            cin >> v4 >> v5;
            int i = LocateVex(G, v4);
            int j = LocateVex(G, v5);
            p1 = new AN[G.A];
            p1[k].adj = j;
            p1[k].next = G.vertices[i].first;
            G.vertices[i].first = &p1[k];
            p2 = new AN[G.A];
            p2[k].adj = i;
            p2[k].next = G.vertices[j].first;
            G.vertices[j].first = &p2[k];
        }
        int p;
        string str;
        cin >> p;
        Print(G, p);
        DFS_AL(G, 0);
        cout << "delete p1 and p2,please cin 'yes'" << endl;
        cin >> str;
        if (str == "yes") {
            delete[] p1;
            delete[] p2;
        }
    }

    //有向图邻接表
    void CreateHDG(ALGraph &G) {
        cin >> G.V >> G.A;
        for (int i = 0; i < G.V; i++) {
            cin >> G.vertices[i].data;
            G.vertices[i].first = NULL;
        }
        for (int k = 0; k < G.A; k++) {
            cin >> v4 >> v5;
            int i = LocateVex(G, v4);
            int j = LocateVex(G, v5);
            p1 = new AN[G.A];
            p1[k].adj = j;
            p1[k].next = G.vertices[i].first;
            G.vertices[i].first = &p1[k];
        }
        int p;
        string str;
//        cin>>p;
//        Print(G,p);
        BFS_AL(G, 0);
        cout << "delete p1 and p2,please cin 'yes'" << endl;
        cin >> str;
        if (str == "yes") {
            delete[] p1;
        }
    }

    //邻接矩阵的深度优先搜索
    void DFS_AM(Map &G, int node) {
        cout << node + 1 << "->";
        visited[node] = 1;
        for (int i = 0; i < G.VexNum; i++) {
            if ((G.arcs[node][i] != 0) && (!visited[i])) DFS_AM(G, i);
        }
    }

    //邻接表的深度优先搜索
    void DFS_AL(ALGraph &G, int node) {
        cout << node + 1 << "->";
        visited[node] = 1;
        AN *p;
        p = G.vertices[node].first;
        while (p != NULL) {
            int w = p->adj;
            if ((!visited[w])) DFS_AL(G, w);
            p = p->next;
        }
    }

    //邻接表的广度优先搜索
    void BFS_AL(ALGraph &G, int node) {
        cout << node + 1 << "->";
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            wp = G.vertices[i].first;
            if (wp == NULL)continue;
            if (!visited[wp->adj]) {
                cout << wp->adj + 1 << "->";
                visited[wp->adj] = 1;
                q.push(wp->adj);
            }
            while (wp->next != NULL) {//while循环判断是否还有子树
                wp = wp->next;
                if (!visited[wp->adj]) {
                    cout << wp->adj + 1 << "->";
                    visited[wp->adj] = 1;
                    q.push(wp->adj);
                }
            }
//            for (wp = G.vertices[i].first; wp->adj >= 0; wp = G.vertices[i].first->next) {
//                if (!visited[wp->adj]) {
//                    cout << wp->adj << "->";
//                    visited[wp->adj] = 1;
//                    q.push(wp->adj);
//                }
//            }
        }
    }

    //普利姆算法
    void prim(Map &map, int n) {
        int k = n, wt;
        for (int i = 0; i < map.VexNum; i++)
            if (i != k) CG[i] = {n, map.arcs[k][i]};
        CG[k].wight = 0;//该点置零可以判断该点是否已经被联通
        for (int i = 1; i < map.VexNum; i++) {
            wt = k;
            k = Min(map, wt);
            int u0 = CG[k].adj;
            int v0 = map.v[k];
            cout << u0 + 1 << " " << v0 + 1 << endl;
            CG[k].wight = 0;
            for (int j = 0; j < map.VexNum; j++) {
                if (map.arcs[k][j] < CG[j].wight)
                    CG[j] = {map.v[k], map.arcs[k][j]};
            }
        }
    }

    //克鲁斯卡尔算法
    void Kruskal(Map &map) {
        MS(map);
        for (int i = 0; i < map.VexNum; i++)
            VS[i] = i;
        for (int i = 0; i < map.arcNum; i++) {
            k1 = Edge[i].head;
            k2 = Edge[i].tail;
            k3 = VS[k1];
            k4 = VS[k2];
            if (k3 != k4) {
                cout << Edge[i].head+1 << Edge[i].tail+1 << endl;
                for (int j = 0; j < map.VexNum; j++)
                    if (VS[j] == k4)VS[j] = k3;
            }
        }
    }

    void Print(Map &map, int n) {//矩阵打印函数
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << map.arcs[i][j] << " ";
            cout << endl;
        }
    }

    void Print(const ALGraph &G, int n) {//表打印函数
        if (G.vertices[n].first != NULL) {
            cout << G.vertices[n].first->adj << " ";
            if (G.vertices[n].first->next != NULL) {
                AN *p;
                p = G.vertices[n].first->next;
                cout << p->adj << " ";
                if (p->next != NULL) {
                    AN *q;
                    q = p->next;
                    cout << q->adj;
                }
            }
        }
    }

private:
    int arcs[10][10];
    int v[10];//顶点信息
    int VexNum, arcNum;

    //克鲁斯卡尔
    int VS[MAX],k1, k2, k3, k4;
    void MS(Map &map) {
        for (int i = 0; i < map.arcNum; i++) {
            int k = i;
            for (int j = i+1; j < map.arcNum; j++) {
                if (Edge[k].wight > Edge[j].wight && Edge[j].wight != 0)
                    k = j;
            }
            Edge[99].head=Edge[i].head;Edge[99].tail=Edge[i].tail;Edge[99].wight=Edge[i].wight;
            Edge[i].head=Edge[k].head;Edge[i].tail=Edge[k].tail;Edge[i].wight=Edge[k].wight;
            Edge[k].head=Edge[99].head;Edge[k].tail=Edge[99].tail;Edge[k].wight=Edge[99].wight;
        }
    }
    //

    bool visited[100];//深度优先搜索

    AN *wp;//广度优先搜索

    int LocateVex(Map &map, int n) {
        return map.v[n];
    }

    int LocateVex(ALGraph &G, int n) {
        return G.vertices[n].data;
    }

    //普利姆算法
    int Min(Map &map, int h) {
        int n, p;
        for (int i = 0; i < map.VexNum; i++)
            if (CG[i].wight != 0) {
                n = map.arcs[h][i];
                p = i;
                break;
            }
        for (int i = 0; i < map.VexNum; i++) {
            if ((map.arcs[h][i] < n) && (CG[i].wight != 0)) {
                n = map.arcs[h][i];
                p = i;
            }
        }
        return p;
    }//求点上的最小带权边
    //
    int v1, v2, v3, v4, v5;//v1,v2,v3邻接矩阵占用，v4,v5邻接表
    AN *p1, *p2;//无向图邻接表
};
//普利姆算法测试点
//6 10
//0 1 2 3 4 5
//0 1 6
//0 2 1
//0 3 5
//1 2 5
//2 3 5
//1 4 3
//2 4 6
//2 5 4
//4 5 6
//3 5 2

#endif //_MYMAP_H
