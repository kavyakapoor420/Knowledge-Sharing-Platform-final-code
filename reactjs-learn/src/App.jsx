import React from 'react'
import './App.css'
import LoggerComponent from './useEffect/LoggerComponent'
import TimerComponent from './useEffect/TimerComponent'
import DataFetcher from './useEffect/DataFetcher'
import ResizeComponent from './useEffect/ResizeComponent'
import MultiEffectComponent from './useEffect/MutiEffectComponent'

function App() {


  return (
    <>
        {/* <LoggerComponent/> */}
        {/* <TimerComponent/>  it will run on very render only  */}
        {/* <DataFetcher/> it will run only on first render  */}
        {/* <ResizeComponent/> */}
        <MultiEffectComponent/>
    </>

  )
}

export default App
