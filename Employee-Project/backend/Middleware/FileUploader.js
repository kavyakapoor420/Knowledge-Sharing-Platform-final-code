const multer=require('multer');

const dotenv=require('dotenv');
dotenv.config();
const {CloudinaryStorage}=require('multer-storage-cloudinary');
const cloundinary=require('cloudinary').v2;

cloundinary.config({
    cloud_name:process.env.CLOUDINARY_CLOUD_NAME,
    api_key:process.env.CLOUDINARY_API_KEY,
    api_secret:process.env.CLOUDINARY_API_SECRET    
})

const storageCloundinary=new CloudinaryStorage({

    cloudinary:cloundinary,
    params:{
        folder:"uploads",
        format:async(req,res)=>'png',
        public_id:(req,file)=>file.originalname.split('.')[0]+''
    }
})


const cloudinaryMulter_fileUpload=multer({
    storage:storageCloundinary
})

module.exports={
    cloudinaryMulter_fileUpload
}