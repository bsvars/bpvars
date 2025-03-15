

#' R6 Class Representing StartingValuesBVARGROUPPANEL
#'
#' @description
#' The class StartingValuesBVARGROUPPANEL presents starting values for the Bayesian
#' hierarchical panel VAR model with country grouping
#' 
#' @examples 
#' # starting values for a Bayesian Panel VAR
#' sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
#' 
#' @export
specify_starting_values_bvarGroupPANEL = R6::R6Class(
  "StartingValuesBVARGROUPPANEL",
  
  inherit = specify_starting_values_bvarPANEL,
  
  public = list(
    
    #' @field group_allocation a numeric vector with integer numbers denoting group allocations
    group_allocation = numeric(),
    
    #' @field A_c an \code{KxNxC} array of starting values for the local parameter 
    #' \eqn{\mathbf{A}_c}. 
    A_c           = array(),
    
    #' @field Sigma_c an \code{NxNxC} array of starting values for the local
    #' parameter \eqn{\mathbf{\Sigma}_c}. 
    Sigma_c       = array(),
    
    #' @field A an \code{KxN} matrix of starting values for the global parameter 
    #' \eqn{\mathbf{A}}. 
    A             = matrix(),
    
    #' @field V an \code{KxK} matrix of starting values for the global parameter 
    #' \eqn{\mathbf{V}}. 
    V             = matrix(),
    
    #' @field Sigma an \code{NxN} matrix of starting values for the global parameter 
    #' \eqn{\mathbf{\Sigma}}. 
    Sigma         = matrix(),
    
    #' @field nu a positive scalar with starting values for the global parameter
    #' \eqn{\nu}.
    nu            = NA,
    
    #' @field m a positive scalar with starting values for the global hyper-parameter
    #' \eqn{m}.
    m             = NA,
    
    #' @field w a positive scalar with starting values for the global hyper-parameter
    #' \eqn{w}.
    w             = NA,
    
    #' @field s a positive scalar with starting values for the global hyper-parameter
    #' \eqn{s}.
    s             = NA,
    
    
    #' @description
    #' Create new starting values StartingValuesBVARGROUPPANEL
    #' @param group_allocation a numeric vector with integer numbers denoting group allocations
    #' @param C a positive integer - the number of countries in the data.
    #' @param N a positive integer - the number of dependent variables in the model.
    #' @param p a positive integer - the autoregressive lag order of the SVAR model.
    #' @param d a positive integer - the number of \code{exogenous} variables in the model.
    #' @return Starting values StartingValuesBVARGROUPPANEL
    #' @examples 
    #' # starting values for Bayesian Panel VAR 2-country model with 4 lags for a 3-variable system.
    #' sv = specify_starting_values_bvarGroupPANEL$new(C = 2, N = 3, p = 1)
    #' 
    initialize = function(group_allocation = 1:C, C, N, p, d = 0){
      
      stopifnot("Argument group_allocation must be a numeric vector with integer numbers denoting groups." = 
                  is.numeric(group_allocation) & all(group_allocation %% 1 == 0))
      stopifnot("Argument group_allocation must be of length C." = 
                  (length(group_allocation) == C))
      
      super$initialize(C, N, p, d)
      
      K                     = N * p + 1 + d
      self$group_allocation = group_allocation
      G                     = length(unique(group_allocation))
      for (g in 1:G) {
        NG = sum(group_allocation == g)
        self$A_c[, , group_allocation == g]     = array(stats::rnorm(K * N, sd = 0.001), c(K, N, NG))
        self$Sigma_c[, , group_allocation == g] = stats::rWishart(1, N + 1, diag(N))[,,1]
      } # END g loop
    }, # END initialize
    
    
    #' @description
    #' Returns the elements of the starting values StartingValuesBVARGROUPPANEL as 
    #' a \code{list}.
    #' 
    #' @examples 
    #' # starting values for a homoskedastic bsvar with 1 lag for a 3-variable system
    #' sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    #' sv$get_starting_values()   # show starting values as list
    #' 
    get_starting_values   = function(){
      list(
        group_allocation = self$group_allocation,
        A_c           = self$A_c,
        Sigma_c       = self$Sigma_c,
        A             = self$A,
        V             = self$V,
        Sigma         = self$Sigma,
        nu            = self$nu,
        m             = self$m,
        w             = self$w,
        s             = self$s
      )
    }, # END get_starting_values
    
    #' @description
    #' Returns the elements of the starting values StartingValuesBVARGROUPPANEL as a \code{list}.
    #' @param last_draw a list containing the same elements as object StartingValuesBVARGROUPPANEL
    #' @return An object of class StartingValuesBVARGROUPPANEL including the last draw 
    #' of the current MCMC as the starting value to be passed to the continuation 
    #' of the MCMC estimation.
    #' 
    #' @examples
    #' sv = specify_starting_values_bvarGroupPANEL$new(rep(1,2), C = 2, N = 3, p = 1)
    #' 
    #' # Modify the starting values by:
    #' sv_list = sv$get_starting_values()   # getting them as list
    #' sv_list$A <- matrix(rnorm(12), 3, 4) # modifying the entry
    #' sv$set_starting_values(sv_list)      # providing to the class object
    #' 
    set_starting_values   = function(last_draw) {
      self$group_allocation = last_draw$group_allocation
      self$A_c            = last_draw$A_c
      self$Sigma_c        = last_draw$Sigma_c
      self$A              = last_draw$A
      self$V              = last_draw$V
      self$Sigma          = last_draw$Sigma
      self$nu             = last_draw$nu
      self$m              = last_draw$m
      self$w              = last_draw$w
      self$s              = last_draw$s
    } # END set_starting_values
  ) # END public
)  # END specify_starting_values_bvarGroupPANEL
  


#' R6 Class representing the specification of the BVARGROUPPANEL model
#'
#' @description
#' The class BVARGROUPPANEL presents complete specification for the Bayesian Panel
#' Vector Autoregression with county groups
#' 
#' @examples 
#' data(ilo_dynamic_panel)
#' spec = specify_bvarGroupPANEL$new(
#'    data = ilo_dynamic_panel,
#'    p = 4,
#'    G = 2
#' )
#' 
#' @export
specify_bvarGroupPANEL = R6::R6Class(
  "BVARGROUPPANEL",
  
  inherit = specify_bvarPANEL,
  
  public = list(
    
    #' @field p a non-negative integer specifying the autoregressive lag order of the model. 
    p                      = numeric(),
    
    #' @field G a non-negative integer specifying the number of country groupings. 
    G                      = numeric(),
    
    #' @field prior an object PriorBSVAR with the prior specification. 
    prior                  = list(),
    
    #' @field data_matrices an object DataMatricesBVARPANEL with the data matrices.
    data_matrices          = list(),
    
    #' @field starting_values an object StartingValuesBVARGROUPPANEL with the starting values.
    starting_values        = list(),
    
    #' @field adaptiveMH a vector of four values setting the adaptive MH sampler 
    #' for nu: adaptive rate, target acceptance rate, the iteration at which to 
    #' start adapting, the initial scaling rate
    adaptiveMH             = numeric(),
    
    #' @description
    #' Create a new specification of the Bayesian Panel VAR model with country 
    #' groupings BVARGROUPPANEL
    #' @param data a list with \code{C} elements of \code{(T_c+p)xN} matrices 
    #' with time series data.
    #' @param p a positive integer providing model's autoregressive lag order.
    #' @param exogenous a \code{(T+p)xd} matrix of exogenous variables. 
    #' @param stationary an \code{N} logical vector - its element set to 
    #' \code{FALSE} sets the prior mean for the autoregressive parameters of the 
    #' \code{N}th equation to the white noise process, otherwise to random walk.
    #' @param type an \code{N} character vector with elements set to "rate" or "real"
    #' determining the truncation of the predictive density to \code{[0, 100]} and
    #' \code{(-Inf, Inf)} (no truncation) for each of the variables.
    #' @param G a positive integer specifying the number of country groups.
    #' @param group_allocation a numeric vector with integer numbers denoting group allocations
    #' @return A new complete specification for the Bayesian Panel VAR model BVARPANEL.
    initialize = function(
    data,
    p = 1L,
    exogenous = NULL,
    stationary = rep(FALSE, ncol(data[[1]])),
    type = rep("real", ncol(data[[1]])),
    G = NULL,
    group_allocation = NULL
    ) {
      stopifnot("Argument data has to contain matrices with the same number of columns." 
                = length(unique(simplify2array(lapply(data, ncol)))) == 1)
      stopifnot("Argument p has to be a positive integer." 
                = ((p %% 1) == 0 & p > 0))
      
      if (!is.null(G)) {
        
        stopifnot("Argument G has to be a positive integer." = ((G %% 1) == 0 & G > 0))
        
        if (!is.null(group_allocation)) {
          stopifnot("Number of groups in argument group_allocation must be equal to the value of argument G." 
                    = length(unique(group_allocation)) == G)
        } else {
          group_allocation = rep(1:G, length.out = length(data))
        }
        
      } else {
        
        if (!is.null(group_allocation)) {
          G = length(unique(group_allocation))
        } else {
          message("No country groupings have been applied.")
          G = length(data)
          group_allocation = 1:length(data)
        }
        
      }
      
      self$p    = p
      self$G    = G
      C         = length(data)
      N         = unique(simplify2array(lapply(data, ncol)))
      d             = 0
      if (!is.null(exogenous)) {
        d           = ncol(exogenous[[1]])
      }
      
      self$data_matrices   = specify_panel_data_matrices$new(data, self$p, exogenous, type)
      self$prior           = specify_prior_bvarPANEL$new(C, N, self$p, d, stationary)
      self$starting_values = specify_starting_values_bvarGroupPANEL$new(group_allocation, C, N, self$p, d)
      self$adaptiveMH      = c(0.44, 0.6)
    }#, # END initialize
    
  ) # END public
) # END specify_bvarGroupPANEL



#' R6 Class Representing PosteriorBVARGROUPPANEL
#'
#' @description
#' The class PosteriorBVARGROUPPANEL contains posterior output and the specification 
#' including the last MCMC draw for the Bayesian Panel VAR model with country grouping. 
#' Note that due to the thinning of the MCMC output the starting value in element 
#' \code{last_draw} might not be equal to the last draw provided in 
#' element \code{posterior}.
#' 
#' @seealso \code{\link{specify_bvarGroupPANEL}}
#' 
#' @examples 
#' # This is a function that is used within estimate()
#' data(ilo_dynamic_panel)
#' set.seed(123)
#' spec = specify_bvarGroupPANEL$new(
#'    data = ilo_dynamic_panel,
#'    p = 4,
#'    G = 2
#' )
#' 
#' #posterior       = estimate(specification, 50)
#' #class(posterior)
#' 
#' @export
specify_posterior_bvarGroupPANEL = R6::R6Class(
  "PosteriorBVARGROUPPANEL",
  
  inherit = specify_posterior_bvarPANEL,
  
  public = list(
    
    #' @field last_draw an object of class BVARGROUPPANEL with the last draw of the 
    #' current MCMC run as the starting value to be passed to the continuation 
    #' of the MCMC estimation using \code{estimate()}. 
    last_draw = list(),
    
    #' @field posterior a list containing Bayesian estimation output.
    posterior = list(),
    
    #' @description
    #' Create a new posterior output PosteriorBVARGROUPPANEL.
    #' @param specification an object of class BVARGROUPPANEL with the last 
    #' draw of the current MCMC run as the starting value.
    #' @param posterior a list containing Bayesian estimation output.
    #' @return A posterior output PosteriorBVARGROUPPANEL.
    initialize = function(specification, posterior) {
      
      stopifnot("Argument specification must be of class BVARGROUPPANEL." = any(class(specification) == "BVARGROUPPANEL"))
      stopifnot("Argument posterior must must contain MCMC output." = is.list(posterior) & is.array(posterior$A) & is.array(posterior$Sigma) & is.array(posterior$V))
      
      self$last_draw    = specification
      self$posterior    = posterior
      
      N = dim(specification$starting_values$A_c)[2]
      K = dim(specification$starting_values$A_c)[1]
      C = dim(specification$starting_values$A_c)[3]
      S = dim(posterior$A)[3]
      
      Sigma_c           = array(NA, c(N, N, C, S))
      A_c               = array(NA, c(K, N, C, S))
      for (s in 1:S) {
        A_c[,,,s]       = posterior$A_c_cpp[s,1][[1]]
        Sigma_c[,,,s]   = posterior$Sigma_c_cpp[s,1][[1]]
      }
      self$posterior$Sigma_c   = Sigma_c
      self$posterior$A_c       = A_c

    } # END initialize
  ) # END public
) # END specify_posterior_bvarGroupPANEL
