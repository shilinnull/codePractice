package CardPlay;

import java.util.List;

public class Test {
    public static void main(String[] args) {
        CardDemo cardDemo = new CardDemo();
        //1. 买52张牌
        List<Card> cardList = cardDemo.buyCard();
        System.out.println(cardList);
        //2. 洗牌
        cardDemo.shuffle(cardList);
        System.out.println(cardList);
        //3. 3个人 每个人 轮流揭牌5张
        List<List<Card>> ret = cardDemo.play(cardList);

        for (int i = 0; i < ret.size(); i++) {
            System.out.println("第"+(i+1)+"个人的牌："+ret.get(i));
        }

        System.out.println("剩下的牌：");
        System.out.println(cardList);
    }
}
