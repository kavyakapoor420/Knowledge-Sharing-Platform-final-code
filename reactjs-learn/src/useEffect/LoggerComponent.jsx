import React,{useState,useEffect} from "react";

function LoggerComponent(){

    const [cnt,setCnt]=useState(0)

    useEffect(()=>{
        console.log('i will run on evry render ',cnt)
    })
    // runs on evyer render no dependency array passed 

    return(
        <>
            <h1>Count is {cnt}</h1>   
            <button onClick={()=>setCnt(cnt+1)}>
                Increment 
            </button> 
        </>
    )
}


export default LoggerComponent