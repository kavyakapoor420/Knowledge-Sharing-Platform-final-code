const EmployeeModel = require("../Models/EmployeeModel");


const createEmployee=async(req,res)=>{
    try{
        const body=req.body ;

        body.profileImage=req.file ? req.file.path : null ;
        const emp=new EmployeeModel(body)
        await emp.save() 
        
        res.status(201).json({message:'employee created successfully',data:emp, success:true})

    }catch(err){
        res.status(500).json({message:'internal server error', success:false})
    }   
}

const getAllEmployess=async(req ,res)=>{
    try{
        const {page,limit,search}=req.query 
        page=page ? parseInt(page) : 1 ;
        limit=limit ? parseInt(limit) :5
        const skip=(page-1)*limit // (1-1)*5=0 no skip give infor to user from page1

        const employees=await EmployeeModel.find({})
        res.status(200).json({message:'employees fetched successfully', data:employees, success:true})

    }catch(err){
        res.status(500).json({message:'internal server error', success:false} )
    }
}

const getEmployeeById=async(req,res)=>{
    try{
         const {id}=req.params ; 
         const emp=await EmployeeModel.findById(id)
         res.status(200).json({message:"get employee by id success", data:emp, success:true})

    }catch(err){
        res.status(500).json({message:'internal server error', success:false} )
    }
}

const deleteEmployeeById=async(req,res)=>{
    try{
        const {id}=req.params ;
        const emp=await EmployeeModel.findByIdAndDelete(id)

        res.status(200).json({mssage:'employee deleted successfully', data:emp, success:true})

    }catch(err){
        res.status(500).json({message:'internal server error', success:false} )
    }
}

const updateEmployeeById=async(req,res)=>{

    try{
         const {name,phone,email,salary,department}=req.body ;
         const {id}=req.params ; 
         let updatedData={
            name,phone,email,salary,department,updatedAt:new Date() 
         }

         if(req.file){
            updatedData.profileImage=req.file.path 
         }

         const updateEmployee=await EmployeeModel.findByIdAndUpdate(id,updatedData,{new:true})

         if(updateEmployee){
            return res.status(404).json({message:'employee  not found',  success:false})
         }

         res.status(200).json({message:'employee updated successfully', data:updateEmployee, success:true})

    }catch(err){
        res.status(500).json({message:'internal server error', success:false} )
    }
}

module.exports={
    createEmployee ,getAllEmployess,getEmployeeById,
    deleteEmployeeById,updateEmployeeById
}