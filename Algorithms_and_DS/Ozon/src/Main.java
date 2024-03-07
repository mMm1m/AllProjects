import java.io.*;
import java.util.*;

class Marks
{
    public int one = 0,two = 0,three = 0,four = 0,five= 0;
    Marks(){};
    public void add(int n){
        if(n == 1) ++this.one;
        else  if(n == 2) ++this.two;
        else  if(n == 3) ++this.two;
        else  if(n == 4) ++this.two;
        else ++this.five;
    }
    public void add(Marks n)
    {
        this.one += n.one;
        this.two += n.two;
        this.three += n.three;
        this.four += n.four;
        this.five += n.five;
    }
    public void delete(Marks n)
    {
        this.one -= n.one;
        this.two -= n.two;
        this.three -= n.three;
        this.four -= n.four;
        this.five -= n.five;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int one = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            int[][] marks = new int[one+1][second+1];
            for(int j = 0; j < one; ++j)
            {
                String str = br.readLine();
                for(int k = 0; k < second; ++k)
                    marks[j+1][k+1] = Integer.parseInt(str.substring(k,k+1));
            }

            Marks[][] pfx = new Marks[one+1][second+1];
            for (int k= 1; k < one + 1; k++) {
                for (int j = 1; j < second + 1; j++) {
                    if(pfx[k][j] == null) pfx[k][j] = new Marks();
                    if(pfx[k-1][j-1] == null) pfx[k-1][j-1] = new Marks();
                    if(pfx[k][j-1] == null) pfx[k][j-1] = new Marks();
                    if(pfx[k-1][j] == null) pfx[k-1][j] = new Marks();
                    pfx[k][j] = pfx[k-1][j];
                    pfx[k][j].add(marks[k][j]);
                    pfx[k][j].add(pfx[k][j-1]);
                    pfx[k][j].delete(pfx[k-1][j-1]);
                }
            }
            for (int k= 1; k < one + 1; k++) {
                for (int j = 1; j < second + 1; j++) {
                    System.out.println(List.of(pfx[k][j].one, pfx[k][j].two, pfx[k][j].three, pfx[k][j].four, pfx[k][j].five));

                }
            }
            System.out.println("\n");
        }


        bw.flush();
        bw.close();
        br.close();
    }
}