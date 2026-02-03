// For Subtask #1, #2 and #3



import java.io.InputStream;

import java.util.HashSet;

import java.util.TreeSet;



class TomJerry_Easy

{

    static IO io = new IO(System.in);

    static HashSet<Integer>[] graph;

    static int n;



    public static void main(String[] args) throws Exception

    {

        for(int tc = io.nextInt(); tc > 0; --tc)

        {

            int i;

            graph = new HashSet[n = io.nextInt()];

            for(i = 0; i < n; ++i)

                graph[i] = new HashSet<>();



            for(i = io.nextInt(); i > 0; --i)

            {

                int a = io.nextInt() - 1, b = io.nextInt() - 1;

                graph[a].add(b);    graph[b].add(a);

            }



            TreeSet<Integer> sortedList = new TreeSet<>((Integer a, Integer b)

                    -> graph[a].size() == graph[b].size()?

                    Integer.compare(a, b): Integer.compare(graph[a].size(), graph[b].size()));

            for(i = 0; i < n; ++i)

                sortedList.add(i);



            int K = 1;

            while(!sortedList.isEmpty())

            {

                K = Math.max(K, graph[sortedList.first()].size());

                remove(sortedList.first(), sortedList);

                while (!sortedList.isEmpty() && graph[sortedList.first()].isEmpty())

                    sortedList.pollFirst();

            }

            io.println(K + 1);

        }

        io.flush();

    }

    static void remove(int vertex, TreeSet<Integer> ts)

    {

        for(int itr: graph[vertex]) {

            ts.remove(itr);

            graph[itr].remove(vertex);

            ts.add(itr);    // Node 'itr' is modified, change is updated in TreeSet 'ts'.

        }

        ts.remove(vertex);

        graph[vertex].clear();

        ts.add(vertex);

    }

}













// Fast IO (to clear Task #9



class IO

{

    static byte[] buf = new byte[2048];

    static int index, total;

    static InputStream in;

    static StringBuilder sb = new StringBuilder();





    IO(InputStream is)

    {

        in = is;

    }



    int scan() throws Exception

    {

        if(index>=total){

            index = 0;

            total = in.read(buf);

            if(total<=0)

                return -1;

        }

        return buf[index++];

    }



    String next() throws Exception

    {

        int c;

        for(c=scan(); c<=32; c=scan());

        StringBuilder sb = new StringBuilder();

        for(; c>32; c=scan())

            sb.append((char)c);

        return sb.toString();

    }



    int nextInt() throws Exception

    {

        int c, val = 0;

        for(c=scan(); c<=32; c=scan());

        boolean neg = c=='-';

        if(c=='-' || c=='+')

            c = scan();

        for(; c>='0' && c<='9'; c=scan())

            val = (val<<3) + (val<<1) + (c&15);

        return neg?-val:val;

    }

    long nextLong() throws Exception

    {

        int c;long val = 0;

        for(c=scan(); c<=32; c=scan());

        boolean neg = c=='-';

        if(c=='-' || c=='+')

            c = scan();

        for(; c>='0' && c<='9'; c=scan())

            val = (val<<3) + (val<<1) + (c&15);

        return neg?-val:val;

    }

    void print(Object a)

    {

        sb.append(a.toString());

    }

    void println(Object a)

    {

        sb.append(a.toString()).append("\n");

    }

    void println()

    {

        sb.append("\n");

    }

    void flush()

    {

        System.out.print(sb);

        sb = new StringBuilder();

    }

}
