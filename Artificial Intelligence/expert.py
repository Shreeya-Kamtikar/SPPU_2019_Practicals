knowledge_base = {
    "cold": ["Tylenol", "Panadol", "Nasal spray", "Wear warm clothes"],
    "influenza": ["Tamiflu", "Panadol", "Zanamivir", "Warm bath, salt gargling"],
    "typhoid": ["Chloramphenicol", "Amoxicillin", "Ciproflaxacin", "Azithromycin", "Bed rest, soft diet"],
    "chicken pox": ["Varicella vaccine", "Immunoglobulin", "Acetomenaphin", "Acyclovir", "Oatmeal, stay at home"],
    "measles": ["Tylenol", "Aleve", "Advil", "Vitamin A", "Rest, liquid intake"],
    "malaria": ["Aralen", "Qualaquin", "Plaquenil", "Mefloquine", "No open air, cover skin"]
}

def respond(symptoms):
    disease = {
        ("headache", "runny nose", "sneezing", "sore-throat"): "cold",
        ("sore-throat", "fever", "headache", "chills", "body-ache"): "influenza",
        ("headache", "abdominal-pain", "poor-appetite", "fever"): "typhoid",
        ("rash", "body-ache", "fever"): "chicken pox",
        ("fever", "runny-nose", "rash", "conjunctivitis"): "measles",
        ("fever", "sweating", "headache", "nausea", "vomiting", "diahrrea"): "malaria"
    }

    for symptoms_set, disease_name in disease.items():
        if set(symptoms) == set(symptoms_set):
            print(f"You may have {disease_name.capitalize()}!")
            print("Please take the following medicines and precautions:")
            for item in knowledge_base[disease_name]:
                print(item)
            return
    print("Diagnosis not found in knowledge base!")

print("Medical Diagnosis Expert System")
options = ["headache", "runny-nose", "sneezing", "sore-throat", "fever", "chills", "body-ache", "abdominal-pain", "poor-appetite", "rash", "conjunctivitis", "sweating", "nausea", "vomiting", "diahrrea"]
print(options)
user_input = input("What are your symptoms? (Separate symptoms with spaces): ").lower().split()
respond(user_input)