public class Int extends Sum {
    private int ans;
    @Override
    public int countSum(String[] args, int i, int j, int r) {
        this.ans += java.lang.Integer.parseInt(args[i].substring(j, r));
        return ans;
    }
}
