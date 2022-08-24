
public class Main {

    public static void main(String[] args) {

        Queue pizzaQueue = new Queue();

        pizzaQueue.enqueue("pepperoni", "1234 Bobcat Trail");
        pizzaQueue.enqueue("sausage", "2345 University Drive");

        pizzaQueue.deliver();

        pizzaQueue.enqueue("extra cheese", "3456 Rickster Road");
        pizzaQueue.enqueue("everything", "4567 King Court");
        pizzaQueue.enqueue("coffee beans", "5678 Java Circle");

        pizzaQueue.deliver();
        pizzaQueue.deliver();
        pizzaQueue.deliver();
        pizzaQueue.deliver();
        pizzaQueue.deliver();
    } //end static main
}
// end Main