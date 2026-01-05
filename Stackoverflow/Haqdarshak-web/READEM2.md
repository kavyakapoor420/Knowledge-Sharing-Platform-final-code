## Development Setup

###  Step 1: Clone the Repository  
```bash
git clone "https://github.com/kavyakapoor420/Knowledge-Sharing-Platform-final-code.git"

cd Stackoverflow

cd Haqdarshak-web
```

This project requires the following credentials:

# MongoDB atlas connection string, gemini API key , sarvam API key , Elastic search api key 

1.) MongoDB Atlas Setup (Database)

Go to:
👉 https://www.mongodb.com/cloud/atlas/register

Create a free account or log in.

Create a Project

Click Build a Database

Choose M0 Free Tier

Give any name

Click Create

Create a Database User

Left Sidebar → Database Access → Add New Database User

Username: admin (or any)

Password: save it securely

Allow IP Access (for local development)

Left Sidebar → Network Access → Add IP Address

Allow Access from Anywhere: 0.0.0.0/0

Get Connection String

Click Connect on your cluster

Choose Connect your application

Select Driver and copy the connection string:

mongodb+srv://<username>:<password>@cluster0.xxxxx.mongodb.net/?retryWrites=true&w=majority

Replace <username> and <password> with your values.

Add this to your .env file later as:
MONGODB_URI2=mongodb+srv://admin:yourpassword@cluster0.xxxxx.mongodb.net/haqdarshak_db?retryWrites=true&w=majority

<img width="783" height="586" alt="Screenshot 2025-12-09 at 12 44 10 AM" src="https://github.com/user-attachments/assets/d0698755-f6ba-4e32-8a72-c03fde483318" />

##  Official Guide -> https://www.mongodb.com/docs/atlas/tutorial/create-atlas-account/

2.) Get Sarvam AI API Key

Go to → https://dashboard.sarvam.ai/
Sign up / Log in
Go to API Keys section → Create New Key
Copy the key

Refer Docs: https://docs.sarvam.ai/

3.) Get Google Gemini API Key

Go to → https://aistudio.google.com/app/apikey
Sign in with Google
Click "Create API Key" (in a new or existing project)
Copy the key

4. Docling – First-Time Installation (Important!)
    Docling needs system-level tools for PDF parsing & OCR.
    Install System Dependencies First
    macOS
    ```
    brew install poppler tesseract
    ```
Docling Official Install Guide:
https://docling-project.github.io/docling/getting_started/installation/


OFfical docs link : https://ai.google.dev/gemini-api/docs/api-key

```

### Step 3: Run the Node.js Backend (Authentication & REST APIs) And frontend (react+vite)

```
docker compose up --build
```

Frontend available at:
 http://localhost:5173

Node backend running at:
 http://localhost:5000
