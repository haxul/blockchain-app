import React from "react"
import Button from "../../Button"
import styled from "styled-components"

const Form = styled.form`
  text-align: center;
`
export class Login extends React.PureComponent {
  state = {
    username: "",
    privateKey: "",
  }

  handleUsername = e => this.setState({ username: e.target.value })
  handlePrivateKey = e => this.setState({ privateKey: e.target.value })

  render() {
    return (
      <Form method="POST" action="/">
        <div className="form-group">
          <input
            type="text"
            className="form-control"
            placeholder="username"
            onChange={this.handleUsername}
          />
        </div>
        <div className="form-group">
          <input
            type="text"
            className="form-control"
            placeholder="private key"
            onChange={this.handlePrivateKey}
          />
        </div>
        <Button />
      </Form>
    )
  }
}
