import React from "react"

export const Wrapper = props => {
  const { Login } = props
  return Login ? (
    <div className="container mt-5">
      <div className="row justify-content-center">
        <div className="col-8">{<Login />}</div>
      </div>
    </div>
  ) : null
}
