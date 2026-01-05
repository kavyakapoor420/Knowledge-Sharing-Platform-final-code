const express=require('express');
const { getEmployeeById, getAllEmployess, createEmployee, deleteEmployeeById, updateEmployeeById } = require('../Controllers/EmployeeController');
const { cloudinaryMulter_fileUpload } = require('../Middleware/FileUploader');

const employeeRouter=express.Router();

employeeRouter.get('/',getAllEmployess)

employeeRouter.get('/',cloudinaryMulter_fileUpload.single("profileImage"),createEmployee)

employeeRouter.get('/:id',getEmployeeById)

employeeRouter.delete('/:id',deleteEmployeeById)

employeeRouter.put('/:id',cloudinaryMulter_fileUpload.single('profileImage'),updateEmployeeById)

module.exports={employeeRouter} ;