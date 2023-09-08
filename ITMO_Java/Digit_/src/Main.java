public class Main
{
    public static void main(String[] args)
    {
        int ans = 0;
        for (int i = 0; i < args.length; i++)
        {
            for (int j = 0; j < args[i].length(); j++)
            {
                int r = j;
                while (r < args[i].length() && !Character.isWhitespace(args[i].charAt(r))) r++;
                if (r > j)
                {
                    if (j + 2 < r && args[i].substring(j, j + 2).toLowerCase().equals("0x")) {
                        Hex h = new Hex();
                        ans += h.countSum(args,i,j,r);
                    }
                    else {
                        Int integer = new Int();
                        ans += integer.countSum(args, i, j, r);
                    }
                    j = r - 1;
                }
            }
        }
        System.out.println(ans);
    }
}
