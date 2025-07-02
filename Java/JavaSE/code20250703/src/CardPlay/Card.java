package CardPlay;

public class Card {
    private String suit;
    private int rank;

    public Card(String suit, int rank){
        this.suit = suit;
        this.rank = rank;
    }

    @Override
    public String toString() {
        return "{"+suit + rank +"} ";
    }
}
