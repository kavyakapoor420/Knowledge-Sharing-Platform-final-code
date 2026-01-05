const express=require('express')
const mongoose=require('mongoose');
const app=express() 

app.use(express.json())
const dotenv=require('dotenv');
dotenv.config();


async function connectDB(){
    await mongoose.connect(process.env.MONGO_URI)
}

connectDB().then(()=>{ 
    console.log('database connected successfully');
}).catch((err)=>{
    console.log('database connection failed',err);
})

app.listen(3000,()=>{
    console.log('server is running on port 3000');
})