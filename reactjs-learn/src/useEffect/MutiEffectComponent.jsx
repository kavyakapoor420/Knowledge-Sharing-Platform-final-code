import React,{useState,useEffect} from "react";


function MultiEffectComponent(){

    const [cnt,setCnt]=useState(0)
    const [second,setSeconds]=useState(0)

    //side effect logic will run eveyrtime when cnt value changes 

    useEffect(()=>{
        console.log('value of count changed',cnt)

    },[cnt])

    useEffect(()=>{
        const intervalId=setInterval(()=>{
            setSeconds(prevSec=>prevSec+1)
        },1000)

        return ()=>{
            console.log('time to stop')
            clearInterval(intervalId)
        }
    },[]) 

    // it will run only on first render 

    return(
        <>
          <h1>cnt is {cnt}</h1>
            <button onClick={()=>setCnt(cnt+1)}>
                Increment 
            </button>

            <h1>seconds are {second}</h1>

        </>
    )
}

export default MultiEffectComponent