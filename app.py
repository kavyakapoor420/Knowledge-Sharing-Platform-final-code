# 1️⃣ Import libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

# For KaggleHub users
import kagglehub
import os

# 2️⃣ Download dataset
path = kagglehub.dataset_download("alexteboul/heart-disease-health-indicators-dataset")
print("Dataset downloaded to:", path)

# Check files inside folder
files = os.listdir(path)
print("Files in folder:", files)

# Assuming there is a CSV file
csv_file = [f for f in files if f.endswith(".csv")][0]
csv_path = os.path.join(path, csv_file)

# 3️⃣ Load dataset
df = pd.read_csv(csv_path)
print("Dataset shape:", df.shape)
print(df.head())

# 4️⃣ Exploratory Data Analysis (EDA)
print("\nData Info:")
print(df.info())

print("\nMissing Values:")
print(df.isnull().sum())

print("\nDescriptive Stats:")
print(df.describe())

# Plot correlation heatmap
plt.figure(figsize=(12,8))
sns.heatmap(df.corr(), annot=True, cmap="coolwarm")
plt.title("Feature Correlation Heatmap")
plt.show()

# 5️⃣ Define Features and Target
# For demonstration, let's predict 'HeartDisease' column if it exists, otherwise pick a numeric target
target_col = "HeartDisease" if "HeartDisease" in df.columns else df.columns[-1]  # change if needed
X = df.drop(columns=[target_col])
y = df[target_col]

# Convert categorical columns to numeric if any
X = pd.get_dummies(X, drop_first=True)

# 6️⃣ Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# 7️⃣ Initialize and Train Linear Regression
lr = LinearRegression()
lr.fit(X_train, y_train)

# 8️⃣ Make Predictions
y_pred_train = lr.predict(X_train)
y_pred_test = lr.predict(X_test)

# 9️⃣ Model Evaluation
print("=== Training Set Evaluation ===")
print("MAE:", mean_absolute_error(y_train, y_pred_train))
print("MSE:", mean_squared_error(y_train, y_pred_train))
print("RMSE:", np.sqrt(mean_squared_error(y_train, y_pred_train)))
print("R2 Score:", r2_score(y_train, y_pred_train))

print("\n=== Test Set Evaluation ===")
print("MAE:", mean_absolute_error(y_test, y_pred_test))
print("MSE:", mean_squared_error(y_test, y_pred_test))
print("RMSE:", np.sqrt(mean_squared_error(y_test, y_pred_test)))
print("R2 Score:", r2_score(y_test, y_pred_test))

# 10️⃣ Plot Actual vs Predicted
plt.figure(figsize=(8,6))
plt.scatter(y_test, y_pred_test, alpha=0.7)
plt.xlabel("Actual")
plt.ylabel("Predicted")
plt.title("Actual vs Predicted Values")
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
plt.show()

# 11️⃣ Residual Analysis
residuals = y_test - y_pred_test
plt.figure(figsize=(8,6))
sns.histplot(residuals, kde=True)
plt.title("Residuals Distribution")
plt.show()

plt.figure(figsize=(8,6))
plt.scatter(y_pred_test, residuals, alpha=0.7)
plt.axhline(y=0, color='r', linestyle='--')
plt.xlabel("Predicted Values")
plt.ylabel("Residuals")
plt.title("Residuals vs Predicted")
plt.show()

# 12️⃣ Feature Coefficients
coeff_df = pd.DataFrame({
    "Feature": X.columns,
    "Coefficient": lr.coef_
}).sort_values(by="Coefficient", key=abs, ascending=False)
print("\nTop Features by Coefficient:")
print(coeff_df.head(10))



# 1. Imports
import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (
    accuracy_score, precision_score, recall_score, f1_score,
    confusion_matrix, roc_curve, roc_auc_score, classification_report
)
from sklearn.preprocessing import StandardScaler

import kagglehub

# 2. Download dataset
path = kagglehub.dataset_download("alexteboul/heart-disease-health-indicators-dataset")
print("Dataset folder:", path)
files = os.listdir(path)
print("Files:", files)
csv_file = [f for f in files if f.endswith(".csv")][0]
csv_path = os.path.join(path, csv_file)

# 3. Load dataset
df = pd.read_csv(csv_path)
print("Shape:", df.shape)
print(df.head())

# 4. Exploratory Data Analysis
print("\nInfo:")
print(df.info())
print("\nMissing values per column:")
print(df.isnull().sum())
print("\nValue counts of target:")
print(df.iloc[:, -1].value_counts())

plt.figure(figsize=(12,8))
sns.heatmap(df.corr(), annot=False, cmap='coolwarm')
plt.title("Feature Correlation Heatmap")
plt.show()

# 5. Preprocessing
# Assume the target column is named something like 'HeartDiseaseorAttack' or similar
target_col = df.columns[-1]  # change if you know exact name
X = df.drop(columns=[target_col])
y = df[target_col]

# Convert categorical if any (here dataset is mostly numeric 0/1)
# But ensure dtype is numeric
X = X.apply(pd.to_numeric, errors='coerce')
y = y.apply(pd.to_numeric, errors='coerce')

# Drop any rows with missing values after conversion
data = pd.concat([X, y], axis=1).dropna()
X = data.drop(columns=[target_col])
y = data[target_col]

# Split into train/test
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# Feature scaling (important for logistic regression with many features)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 6. Train model (Logistic Regression)
logreg = LogisticRegression(max_iter=1000, random_state=42)
logreg.fit(X_train_scaled, y_train)

# 7. Predict
y_pred = logreg.predict(X_test_scaled)
y_pred_proba = logreg.predict_proba(X_test_scaled)[:,1]

# 8. Evaluation
print("\n=== Classification Report ===")
print(classification_report(y_test, y_pred))

acc = accuracy_score(y_test, y_pred)
prec = precision_score(y_test, y_pred)
rec = recall_score(y_test, y_pred)
f1 = f1_score(y_test, y_pred)
auc = roc_auc_score(y_test, y_pred_proba)

print("Accuracy:", acc)
print("Precision:", prec)
print("Recall:", rec)
print("F1 Score:", f1)
print("ROC AUC:", auc)

print("\nConfusion Matrix:")
cm = confusion_matrix(y_test, y_pred)
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()

# ROC Curve
fpr, tpr, thresholds = roc_curve(y_test, y_pred_proba)
plt.figure(figsize=(8,6))
plt.plot(fpr, tpr, label=f"AUC = {auc:.2f}")
plt.plot([0,1], [0,1], 'r--')
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC Curve')
plt.legend()
plt.show()

# 9. Feature coefficients
coeff_df = pd.DataFrame({
    'Feature': X.columns,
    'Coefficient': logreg.coef_[0]
}).sort_values(by='Coefficient', key=lambda x: abs(x), ascending=False)

print("\nTop Features by coefficient magnitude:")
print(coeff_df.head(10))

# 10. Additional Analysis: class imbalance
print("\nClass distribution in y_train:")
print(y_train.value_counts(normalize=True))


#include <bits/stdc++.h>
using namespace std;

class Line {
public:
    int x1, y1, x2, y2;
    Line(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};

bool isHorizontal(Line &l) {
    return l.y1 == l.y2;
}

bool isVertical(Line &l) {
    return l.x1 == l.x2;
}

// Check if a vertical line V intersects horizontal line H
bool intersects(Line &H, Line &V) {
    int hy = H.y1;
    int hx1 = min(H.x1, H.x2);
    int hx2 = max(H.x1, H.x2);

    int vx = V.x1;
    int vy1 = min(V.y1, V.y2);
    int vy2 = max(V.y1, V.y2);

    return (vx >= hx1 && vx <= hx2 && hy >= vy1 && hy <= vy2);
}

int main() {
    int n;
    cin >> n;

    vector<Line> horizontals;
    vector<Line> verticals;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line line(x1, y1, x2, y2);

        if(isHorizontal(line)) horizontals.push_back(line);
        else verticals.push_back(line);
    }

    long long ans = 0;

    // Check each pair of horizontal lines
    for(int i = 0; i < horizontals.size(); i++) {
        for(int j = i + 1; j < horizontals.size(); j++) {

            vector<int> verticalsIntersecting;

            for(int k = 0; k < verticals.size(); k++) {
                if(intersects(horizontals[i], verticals[k]) &&
                   intersects(horizontals[j], verticals[k])) {
                    verticalsIntersecting.push_back(k);
                }
            }

            int cnt = verticalsIntersecting.size();
            if(cnt >= 2) {
                ans += 1LL * cnt * (cnt - 1) / 2;
            }
        }
    }

    cout << ans;
    return 0;
}
