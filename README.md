## Prerequisites

### Step 1: Obtain Required API Credentials

Before running the project, you need to obtain the following API keys and credentials:

---

### 1. Sarvam AI API Key
- Visit: https://www.sarvam.ai/
- Sign up and navigate to the **API** section to generate your API key  
-  Documentation: https://docs.sarvam.ai/

---

### 2. Google Gemini API Key
- Visit: https://ai.google.dev/
- Go to **Google AI Studio**
- Click **Get API Key** to generate your Gemini API key  
-  Get API key: https://aistudio.google.com/app/apikey  
-  Documentation: https://ai.google.dev/gemini-api/docs/api-key

---

### 3. MongoDB Atlas Connection String
- Visit: https://www.mongodb.com/cloud/atlas
- Create a free account and set up a cluster
- Follow the connection guide to obtain your connection string  
-  Official Guide: https://www.mongodb.com/docs/atlas/tutorial/create-atlas-account/

**Connection String Format:**
mongodb+srv://<username>:<password>@<cluster-url>/<database>?retryWrites=true&w=majority


<img width="783" height="586" alt="MongoDB Atlas Setup" src="https://github.com/user-attachments/assets/d0698755-f6ba-4e32-8a72-c03fde483318" />

---

### 4. Hugging Face Access Token
- Visit: https://huggingface.co/
- Sign up or log in
- Go to **Settings → Access Tokens**
- Create a new token with **read** permissions  
- Token Page: https://huggingface.co/settings/tokens

---

### 5. Elasticsearch API Key
- Visit: https://www.elastic.co/cloud/
- Sign up for **Elastic Cloud** or use a self-hosted instance
- Follow the API key documentation to generate an API key

---

## Dependencies for OCR & Docling Parsing

 **Important (First-Time Installation)**  
Docling requires system-level tools for **PDF parsing and OCR**.

### macOS System Dependencies
Install the required packages using Homebrew:

```bash
brew install poppler tesseract
```
[Docling Official Installation Guide]:(https://docling-project.github.io/docling/getting_started/installation/)



### Setup Instructions

Step 1: Clone the Repository  
```bash
  git clone "https://github.com/kavyakapoor420/Knowledge-Sharing-Platform-final-code.git"
  
  cd Stackoverflow
  
  cd Haqdarshak-web
```

### Step 2: Docker Setup- Run the Node.js Backend (Authentication & REST APIs) And frontend (react+vite)

```
docker compose up --build
```

Frontend available at:
 http://localhost:5173

Node backend running at:
 http://localhost:5000

 ### this step is optinal -for local setup 

  ```
  bash
   cd backend
   npm i
   nodemon index.js 

   cd frontend
   npm i
   npm run dev 
```




-------



### Prerequisites

** Step 1: Obtain Required API Credentials** 
- Before running the project, you need to obtain the following API keys and credentials:
  1. Sarvam AI API Key

  Visit: https://www.sarvam.ai/
  Sign up and navigate to the API section to generate your API key
 - [Documentation](https://docs.sarvam.ai/)

  2. Google Gemini API Key

      Visit: https://ai.google.dev/
      Go to Google AI Studio
      Click "Get API Key" to generate your Gemini API key
    - Get API key from [Google AI Studio](https://aistudio.google.com/app/apikey)
    - [Documentation](https://ai.google.dev/gemini-api/docs/api-key)

  
  3. MongoDB Atlas Connection String
  
  Visit: https://www.mongodb.com/cloud/atlas
  Create a free account and set up a cluster
  Follow the connection guide to get your connection string
  
   - [Official Guide](https://www.mongodb.com/docs/atlas/tutorial/create-atlas-account/)
  
  Format: mongodb+srv://<username>:<password>@<cluster-url>/<database>?retryWrites=true&w=majority

  <img width="783" height="586" alt="Screenshot 2025-12-09 at 12 44 10 AM" src="https://github.com/user-attachments/assets/d0698755-f6ba-4e32-8a72-c03fde483318" />

  4. Hugging Face Token

     Visit: https://huggingface.co/
    - Sign up at [Hugging Face](https://huggingface.co/)
    - Get your access token from [Account Settings](https://huggingface.co/settings/tokens)
    Sign up and go to Settings → Access Tokens
    Create a new token with read permissions

  5. Elasticsearch API Key
  
  Visit: https://www.elastic.co/cloud/
  Sign up for Elastic Cloud or use a self-hosted instance
  Follow the API key documentation to generate an API key

** Dependencies for OCR and Docling parsing installation**

  Docling – First-Time Installation (Important!) Docling needs system-level tools for PDF parsing & OCR. Install System Dependencies First macOS
  brew install poppler tesseract
  Docling Official Install Guide: https://docling-project.github.io/docling/getting_started/installation/

   ```
    bash
    brew install poppler tesseract

   ```

### Setup Instructions

Step 1: Clone the Repository  
```bash
  git clone "https://github.com/kavyakapoor420/Knowledge-Sharing-Platform-final-code.git"
  
  cd Stackoverflow
  
  cd Haqdarshak-web
```

### Step 2: Docker Setup- Run the Node.js Backend (Authentication & REST APIs) And frontend (react+vite)

```
docker compose up --build
```

Frontend available at:
 http://localhost:5173

Node backend running at:
 http://localhost:5000

 ### this step is optinal -for local setup 

  ```
  bash
   cd backend
   npm i
   nodemon index.js 

   cd frontend
   npm i
   npm run dev 
```




