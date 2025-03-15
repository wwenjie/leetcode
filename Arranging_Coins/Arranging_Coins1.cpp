// 最简单的方法，复杂度比较高

int arrangeCoins(int n) {
    int row = 1;
    while(n >= row){
        n -= row;
        row++;
    }
    return row-1;
}
