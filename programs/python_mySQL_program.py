import mysql.connector      

# ---------- helper to print the table ----------
def show_table(cursor, title):
    print("\n" + title)
    cursor.execute("SELECT * FROM EMP_SELECTION")
    rows = cursor.fetchall()
    cols = [c[0] for c in cursor.description]
    print(cols)
    for r in rows:
        print(r)

# ---------- (b) connect to MySQL server ----------
con = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root123"
)
cursor = con.cursor()
print("Connected to MySQL server successfully.")

# ---------- (a) create database SELECTION_DB ----------
cursor.execute("CREATE DATABASE IF NOT EXISTS SELECTION_DB")
cursor.execute("USE SELECTION_DB")
print("Database SELECTION_DB is ready.")

# ---------- (c) create table EMP_SELECTION ----------
cursor.execute("DROP TABLE IF EXISTS EMP_SELECTION")
cursor.execute("""
    CREATE TABLE EMP_SELECTION (
        FIRST_NAME VARCHAR(30),
        LAST_NAME  VARCHAR(30),
        AGE        INT,
        GENDER     CHAR(1),
        INCOME     FLOAT
    )
""")
print("Table EMP_SELECTION created.")

# ---------- (d-i) add column address ----------
cursor.execute("ALTER TABLE EMP_SELECTION ADD ADDRESS VARCHAR(50)")
print("Column ADDRESS added.")

# ---------- (d-ii) insert records ----------
sql = """INSERT INTO EMP_SELECTION
         (FIRST_NAME, LAST_NAME, AGE, GENDER, INCOME, ADDRESS)
         VALUES (%s, %s, %s, %s, %s, %s)"""
data = [
    ("Rahul", "Sharma", 25, "M", 35000, "Panipat"),
    ("Priya", "Verma",  30, "F", 52000, "Delhi"),
    ("Aman",  "Singh",  17, "M", 12000, "Karnal"),
    ("Neha",  "Gupta",  16, "F", 10000, "Sonipat"),
    ("Vikas", "Yadav",  40, "M", 60000, "Rohtak"),
]
cursor.executemany(sql, data)
con.commit()
show_table(cursor, "After INSERT:")

# ---------- (d-iii) increase AGE of all males by 1 ----------
cursor.execute("UPDATE EMP_SELECTION SET AGE = AGE + 1 WHERE GENDER = 'M'")
con.commit()
show_table(cursor, "After UPDATE (males' age + 1):")

# ---------- (d-iv) delete records where AGE < 18 ----------
cursor.execute("DELETE FROM EMP_SELECTION WHERE AGE < 18")
con.commit()
show_table(cursor, "After DELETE (AGE < 18):")

cursor.close()
con.close()
print("\nConnection closed.")
