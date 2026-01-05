import { useEffect, useState } from "react"

// it will run only on first render 

function  ResizeComponent(){

    const [windowWidth,setWindowWidth]=useState(window.innerWidth)

    useEffect(()=>{
        const handleResize=()=>setWindowWidth(window.innerWidth)
        
        console.log('event listener added')

        window.addEventListener('resize',handleResize)


        return ()=>{
            console.log('event listener removed')
            window.removeEventListener('resize',handleResize)
        }
    },[])

    return(
        <>
           <h1>
            Window width :{windowWidth}
           </h1>
        </>
    )
}

export default ResizeComponent