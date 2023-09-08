public class Hex extends Sum
{
    private int ans;
    @Override
    public int countSum(String[] args, int i, int j, int r) {
        this.ans += java.lang.Integer.parseUnsignedInt(args[i].substring(j + 2, r), 16);
        return this.ans;
    }
}
