class CardPayment implements Payment {
    @Override
    public void pay() {
        System.out.println("Paying by card");
    }
}