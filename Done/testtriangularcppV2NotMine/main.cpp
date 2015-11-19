//
// ACM UVa Problem #209
// http://acm.uva.es/p/v2/209.html
//
// Author:  ATField
// Email:   atfield_zhang@hotmail.com
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    65535

struct point
{
public :
    bool is_coincide(const point &pt) const
    {
        // not allow testing points with same coordinates
        if( _x == pt._x && _y == pt._y )
            return false;

        if( _y == pt._y )
            return true;
        else
        {
            int k1 = abs( _x - pt._x );
            int k2 = abs( _y - pt._y );

            if( k1 == k2 )
                return true;
        }

        return false;
    }

    int get_dist(const point &pt) const
    {
        // not allow testing points with same coordinates
        if( _x == pt._x && _y == pt._y )
            return 0;

        if( _y == pt._y )
            return abs(_x - pt._x) >> 1;        // need to divide by 2
        else
        {
            int k1 = abs( _x - pt._x );
            int k2 = abs( _y - pt._y );

            if( k1 == k2 )
                return k1;
        }

        return 0;
    }

public :
    static const int X_DELTA = 2;
    static const int Y_DELTA = 3;
    static const int LEN = 4;

public :
    int        _x;
    int        _y;
    int     _valid;

private :
    static point s_all_points[MAX];

public :
    static void prepare()
    {
        int level = 0;
        int before_next_level = 1;
        int next_x = 0;
        int next_y = 0;

        for( int i = 1; i < MAX ; ++i )
        {
            s_all_points[i]._x = next_x;
            s_all_points[i]._y = next_y;
            before_next_level--;

            if( before_next_level == 0 )
            {
                level++;
                before_next_level = level + 1;
                next_x = -level;
                next_y++;
            }
            else
                next_x += 2;

        }


    }

    static point *all_points()
    {
        return s_all_points;
    }
};

point point::s_all_points[MAX];

bool check_triangle(int *n)
{
    // 1. Duplicates
    // No need to check duplicate because the following checks will do

    // 2. Coincide
    // Check every edge
    point *points = point::all_points();
    if( points[n[0]].is_coincide(points[n[1]]) &&
        points[n[0]].is_coincide(points[n[2]]) &&
        points[n[1]].is_coincide(points[n[2]]) )
    {
        // 3. Same length
        // Check every edge
        int len = points[n[0]].get_dist(points[n[1]]);
        if( len == points[n[0]].get_dist(points[n[2]]) &&
            len == points[n[1]].get_dist(points[n[2]]) )
            return true;
    }

    return false;
}


bool init_adj(int *n, int num, int adj[6][6])
{
    point *points = point::all_points();

    for( int i = 0; i < num; ++i )
    {
        for( int j = i; j < num; ++j )
        {
            if( i == j )
            {
                adj[i][j] = 0;
                adj[j][i] = 0;
            }
            else
            {
                // 1. Duplicates
                // Return false when found duplicate
                if( n[i] == n[j] )
                    return false;

                // 2. Coincide & Len (When not coincide, len = 0)
                adj[i][j] = points[n[i]].get_dist(points[n[j]]);
                adj[j][i] = adj[i][j];
            }
        }
    }


    return true;
}

int find_same_len_loop(int adj[6][6], int num)
{
    int stack[6];
    int used[6];
    int next[6];

    for( int i = 1; i < num; ++i )
    {
        int len = adj[0][i];

        // skip non-connected dots
        if( len == 0 ) continue;

        // initialize "used" array & "next" array
        for( int j = 0; j < num; ++j )
        {
            used[j] = 0;
        }

        int top = 0;
        stack[0] = i;
        used[i] = 1;
        next[0] = -1;

        top++;

        while( top > 0 )
        {
            next[top-1]++;

            // checked all the connected points?
            if( next[top-1] >= num )
            {
                // yes, then pop the stack
                top--;
                used[stack[top]] = 0;
            }
            else
            {
                int next_point = next[top-1];

                // follow non-used, same-length edge
                if( used[next_point] == 0 && len == adj[stack[top-1]][next_point] )
                {
                    stack[top] = next_point;
                    used[next_point] = 1;

                    // don't allow pushing 0 into stack before the last point
                    if( top < num - 1 )
                        next[top] = 0;
                    else
                        next[top] = -1;

                    top++;

                    // stack is full? found a loop
                    if( top == num )
                        return len;
                }
            }
        }

        // if this doesn't work, delete all edges starting from id 0 of this len
        for( int j = i; j < num; ++j )
            if( adj[0][j] == len )
                adj[0][j] = 0;
    }

    return 0;
}

bool check_parallelogram(int *n)
{
    int adj[6][6];
    if(!init_adj(n, 4, adj))
        return false;           // found duplicate

    if(find_same_len_loop(adj, 4))
        return true;

    return false;
}

bool check_hexagon(int *n)
{
    int adj[6][6];
    if(!init_adj(n, 6, adj))
        return false;           // found duplicate

    if(find_same_len_loop(adj, 6))
        return true;

    return false;
}

int main()
{
    point::prepare();

    while(1)
    {
        char input[255];
        if( gets(input) == NULL )
            break;
        else if( strlen(input) == 0 )
            break;

        int n[6];
        int fields = sscanf( input, "%d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5] );

        printf("%s ", input);

        switch(fields)
        {
            case 3:
                {
                    bool is_triangle = check_triangle(n);

                    if( is_triangle )
                    {
                        puts("are the vertices of a triangle");
                        continue;
                    }

                    break;
                }

            case 4:
                {
                    bool is_parallelogram = check_parallelogram(n);

                    if( is_parallelogram )
                    {
                        puts("are the vertices of a parallelogram");
                        continue;
                    }

                    break;
                }

            case 6:
                {
                    bool is_hexagon = check_hexagon(n);

                    if( is_hexagon )
                    {
                        puts("are the vertices of a hexagon");
                        continue;
                    }

                    break;
                }
        }

        puts("are not the vertices of an acceptable figure");

    }

    return 0;
}
