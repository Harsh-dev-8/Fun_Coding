import pandas as pd

# read the dataset
df = pd.read_csv("employees.csv")

# print all features (columns)
print("Features (columns) of the dataset:")
for col in df.columns:
    print(col)

# select only numeric columns
numeric = df.select_dtypes(include="number")
print("\nNumeric features:", list(numeric.columns))

# descriptive statistics of every numeric feature
for col in numeric.columns:
    print("\n----- Statistics of", col, "-----")
    print("Count              :", numeric[col].count())
    print("Maximum            :", numeric[col].max())
    print("Minimum            :", numeric[col].min())
    print("Mean               :", round(numeric[col].mean(), 2))
    print("Median             :", numeric[col].median())
    print("Variance           :", round(numeric[col].var(), 2))
    print("Standard Deviation :", round(numeric[col].std(), 2))
