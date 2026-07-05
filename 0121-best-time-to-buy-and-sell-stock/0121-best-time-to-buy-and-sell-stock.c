int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;

    int min_price = prices[0], max_price = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        else if (prices[i] - min_price > max_price) {
            max_price = prices[i] - min_price; 
        }
    }

    return max_price;
}