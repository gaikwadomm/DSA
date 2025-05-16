import mysql.connector

# Connect to your local MySQL database
conn = mysql.connector.connect(
    host="localhost",        # or 127.0.0.1
    user="root",             # your MySQL username
    password="OM#sql123",  # your MySQL password
    database="BANKING_TRANSACTIONS"
)

cursor = conn.cursor()

# Take input from terminal
sender = int(input("Enter sender's Account ID: "))
receiver = int(input("Enter receiver's Account ID: "))
amount = float(input("Enter amount to transfer: "))

try:
    conn.start_transaction()

    # Check sender balance
    cursor.execute("SELECT Balance FROM Accounts WHERE AccountID = %s", (sender,))
    sender_balance_result = cursor.fetchone()
    
    if not sender_balance_result:
        raise Exception("Sender account not found.")

    sender_balance = sender_balance_result[0]

    if sender_balance < amount:
        raise Exception("Insufficient balance.")

    # Check if receiver exists
    cursor.execute("SELECT COUNT(*) FROM Accounts WHERE AccountID = %s", (receiver,))
    if cursor.fetchone()[0] == 0:
        raise Exception("Receiver account does not exist.")

    # Deduct from sender
    cursor.execute("UPDATE Accounts SET Balance = Balance - %s WHERE AccountID = %s", (amount, sender))

    # Add to receiver
    cursor.execute("UPDATE Accounts SET Balance = Balance + %s WHERE AccountID = %s", (amount, receiver))

    conn.commit()
    print("Transaction successful!")

except Exception as e:
    conn.rollback()
    print("Transaction failed:", str(e))

finally:
    cursor.close()
    conn.close()
