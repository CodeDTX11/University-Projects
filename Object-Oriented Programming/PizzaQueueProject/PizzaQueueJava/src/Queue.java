public class Queue {

    class Pizza {

        String ingredient, address;
        Pizza next;

        public Pizza(String ingredient, String address) {
            this.ingredient = ingredient;
            this.address = address;
            this.next = null;
        }
    }

    public Pizza head = null;
    public Pizza tail = null;

    public void enqueue(String ingredient, String address) {

        Pizza newPizza = new Pizza(ingredient, address);

        if (head == null) {
            head = newPizza;
            tail = newPizza;
        } else {
            tail.next = newPizza;
            tail = newPizza;
        }
    }

    public void deliver() {
        if (head == null) {
            System.out.println("No deliveries pending");
        } else {
            System.out.println("Deliver a pizza with " + head.ingredient + " to " + head.address);
            head = head.next;
        }
    }
}
