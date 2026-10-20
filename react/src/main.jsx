import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import Home  from './Home.jsx'
import Header from './components/Header.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <Home />
    <Header />
  </StrictMode>,
)
