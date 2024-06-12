

@ManagedBean
@SessionScoped
public class pr9Validate {
    private String username;
    private String password;

    public String login() {
        if ("harshil".equals(username) && "123".equals(password)) {
            return "welcome?faces-redirect=true";
        } else {
            return "error?faces-redirect=true";
        }
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
