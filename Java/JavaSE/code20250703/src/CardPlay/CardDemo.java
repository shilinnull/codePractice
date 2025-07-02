package CardPlay;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class CardDemo {

    public static final String[] suits = {"♥", "♠", "♣", "♦"};

    public List<Card> buyCard() {
        List<Card> cardList = new ArrayList<>();
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 4; j++) {
                String suit = suits[j];
                Card card = new Card(suit, i);
                cardList.add(card);
            }
        }
        return cardList;
    }

    private void swap(List<Card> cardList,int i,int j) {
        Card tmp = cardList.get(i);
        cardList.set(i,cardList.get(j));
        cardList.set(j, tmp);
    }

    public void shuffle(List<Card> cardList) {
        Random random = new Random();
        for (int i = cardList.size()-1; i > 0 ; i--) {
            int index = random.nextInt(i);
            swap(cardList,i,index);
        }
    }

    public List<List<Card>> play(List<Card> cardList) {
        List<Card> hand0 = new ArrayList<>();
        List<Card> hand1 = new ArrayList<>();
        List<Card> hand2 = new ArrayList<>();

        List<List<Card>> hand = new ArrayList<>();
        hand.add(hand0);
        hand.add(hand1);
        hand.add(hand2);

        // 三个人，每个人轮流抓 5 张牌
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                Card card = cardList.remove(0);
                hand.get(j).add(card);
            }
        }
        return hand;
    }
}
