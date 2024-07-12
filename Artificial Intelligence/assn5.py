def chatbot(user_input, chatbot_rules):
    user_input = user_input.lower()
    for key in chatbot_rules:
        if key in user_input:
            return chatbot_rules[key]
    print("Restobot: I'm sorry, but I'm not able to assist with that. How else can I help you?")

def add_question_answer(chatbot_rules, add_question, add_answer):
    chatbot_rules[add_question] = add_answer

def main():
    chatbot_rules = {
        "menu": "Sure! Here's our menu: idli, vada, sambar",
        "reservation": "To make a reservation, please call us or email us.",
        "location": "We are located at [insert address].",
        "thank you": "You're welcome! Enjoy your meal!",
        "phone": "Its 7689054368",
        "email": "restaurant@gmail.com",
        "cost": "500 for 2 people",
        "rating": "5.0"
    }

    while True:
        print("1. Chat\n2. Add Questions\n3. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            print("Hello I'm Restobot! I can help you with the following information: ")
            for question in chatbot_rules:
                print(question)
            user_input = input("Ask Restobot: ")
            bot_response = chatbot(user_input, chatbot_rules)
            if(bot_response):
                print("Restobot:", bot_response)
            print("______________________________________")

        elif choice == '2':
            add_question = input("Add your keyword here: ")
            add_answer = input("Add the corresponding response: ")
            add_question_answer(chatbot_rules, add_question, add_answer)
            print("Added")

        elif choice == '3':
            print("Thanks for using RestoBot")
            break

if __name__ == '__main__':
    main()
